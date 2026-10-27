#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <atomic>
#include <iomanip>

using namespace std;

const int n = 800;

int A[n][n];
int B[n][n];
int C[n][n];

// Атомарный флаг: потокобезопасная переменная типа bool.
// Потоки ждут, пока главный поток не поставит её в true.
atomic<bool> start_flag(false);

void multiplyRows(int start_row, int end_row) {
    // Поток ждёт разрешения начать вычисления.
    // yield() говорит системе: "передай процессор другому потоку",
    // поэтому это не активное ожидание в чистом виде.
    while (!start_flag.load()) {
        this_thread::yield();
    }
    for (int i = start_row; i < end_row; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                A[i][j] += B[i][k] * C[i][k];
            }
        }
    }
}

int main() {
    unsigned int num_threads = thread::hardware_concurrency();
    if (num_threads == 0) {
        num_threads = 1;
    }
    cout << "threads: " << num_threads << endl;
    vector<thread> threads;
    int rows_per_thread = n / num_threads;
    int start_row = 0;
    // 1. Создаём все потоки ДО запуска таймера.
    for (unsigned int t = 0; t < num_threads; t++) {
        int end_row = start_row + rows_per_thread;
        if (t == num_threads - 1) {
            end_row = n;
        }
        threads.emplace_back(multiplyRows, start_row, end_row);
        start_row = end_row;
    }
    // 2. Включаем таймер только перед началом вычислений.
    auto start = chrono::high_resolution_clock::now();
    // 3. Разрешаем потокам начать работу.
    start_flag.store(true);
    // 4. Ждём завершения всех потоков.
    for (thread& th : threads) {
        th.join();
    }
    // 5. Останавливаем таймер после того, как все вычисления точно закончились.
    auto end = chrono::high_resolution_clock::now();
    double ms = chrono::duration<double, milli>(end - start).count();
    cout << "Compute time: " << ms << " ms" << endl;
    return 0;
}