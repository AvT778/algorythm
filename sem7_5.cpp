#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <atomic>

using namespace std;

const int n = 800;

int A[n][n];
int B[n][n];
int C[n][n];

atomic<bool> start_flag(false);

void multiplyRows(int start_row, int end_row) {
    // Потоки ждут разрешения начать вычисления.
    while (!start_flag.load()) {
        this_thread::yield();
    }
    // Изменённый, более медленный порядок циклов: (i, j, k).
    for (int i = start_row; i < end_row; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                A[i][j] += B[i][k] * C[k][j];
            }
        }
    }
}

int main() {
    const int num_threads = 4;
    vector<thread> threads;
    int rows_per_thread = n / num_threads;
    int start_row = 0;
    // Создаём 4 потока до запуска таймера.
    for (int t = 0; t < num_threads; t++) {
        int end_row = start_row + rows_per_thread;
        // Последний поток обрабатывает оставшиеся строки.
        if (t == num_threads - 1) {
            end_row = n;
        }
        threads.emplace_back(multiplyRows, start_row, end_row);
        start_row = end_row;
    }
    // Таймер запускаем только перед вычислениями.
    auto start = chrono::high_resolution_clock::now();
    start_flag.store(true);
    // Ждём завершения всех потоков.
    for (thread& th : threads) {
        th.join();
    }
    auto end = chrono::high_resolution_clock::now();
    double ms = chrono::duration<double, milli>(end - start).count();
    cout << "n = " << n << endl;
    cout << "Threads: " << num_threads << endl;
    cout << "Loop order: (i, j, k)" << endl;
    cout << "Time: " << ms << " ms" << endl;
    return 0;
}