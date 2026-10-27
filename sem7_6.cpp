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

// Атомарный флаг: главный поток разрешает потокам начать работу.
atomic<bool> start_flag(false);

// Каждый поток обрабатывает строки от start_row до end_row (не включая end_row).
void multiplyRows(int start_row, int end_row) {
    // Потоки ждут, пока главный поток не включит таймер
    // и не разрешит начало вычислений.
    while (!start_flag.load()) {
        this_thread::yield();
    }
    // Порядок (i, k, j): внутренний цикл идёт по столбцам,
    // поэтому элементы C[k][j] читаются последовательно — это лучше для кэша.
    for (int i = start_row; i < end_row; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                A[i][j] += B[i][k] * C[k][j];
            }
        }
    }
}

int main() {
    // Определяем количество аппаратных потоков процессора.
    unsigned int num_threads = thread::hardware_concurrency();
    // Если система не смогла определить количество, используем один поток.
    if (num_threads == 0) {
        num_threads = 1;
    }
    vector<thread> threads;
    // Делим строки матрицы A между потоками.
    int rows_per_thread = n / num_threads;
    int start_row = 0;
    // Создаём все потоки ДО запуска таймера.
    for (unsigned int t = 0; t < num_threads; t++) {
        int end_row = start_row + rows_per_thread;
        // Последний поток забирает оставшиеся строки,
        // если n не делится ровно на количество потоков.
        if (t == num_threads - 1) {
            end_row = n;
        }
        threads.emplace_back(multiplyRows, start_row, end_row);
        start_row = end_row;
    }
    // Запускаем таймер непосредственно перед вычислениями.
    auto start = chrono::high_resolution_clock::now();
    // Разрешаем потокам начать работу.
    start_flag.store(true);
    // Ждём завершения всех потоков.
    for (thread& th : threads) {
        th.join();
    }
    // Останавливаем таймер после завершения всех вычислений.
    auto end = chrono::high_resolution_clock::now();
    double ms = chrono::duration<double, milli>(end - start).count();
    cout << "Matrix size: " << n << " x " << n << endl;
    cout << "Threads: " << num_threads << endl;
    cout << "Loop order: (i, k, j)" << endl;
    cout << "Compute time: " << ms << " ms" << endl;
    return 0;
}