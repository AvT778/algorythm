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

void multiplyRows(int start_row, int end_row) {
    for (int i = start_row; i < end_row; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                A[i][j] += B[i][k] * C[i][k];
            }
        }
    }
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    // Сколько ядер доступно программе.
    unsigned int num_threads = thread::hardware_concurrency();
    // На случай, если система не смогла определить количество ядер.
    if (num_threads == 0) {
        num_threads = 1;
    }
    vector<thread> threads;
    // Размер части работы для каждого потока.
    int rows_per_thread = n / num_threads;
    int start_row = 0;
    for (unsigned int t = 0; t < num_threads; t++) {
        int end_row = start_row + rows_per_thread;
        // Последний поток забирает оставшиеся строки.
        // Это нужно, если n не делится ровно на количество потоков.
        if (t == num_threads - 1) {
            end_row = n;
        }
        // Создаём поток и сразу передаём ему диапазон строк.
        threads.emplace_back(multiplyRows, start_row, end_row);
        start_row = end_row;
    }
    // Ждём, пока все потоки закончат работу.
    for (thread& th : threads) {
        th.join();
    }
    volatile int result = 0;
    for (int i = 0; i < 1000; ++i) {
        result += i * 2;
    }
    auto end = chrono::high_resolution_clock::now();
    double ms = chrono::duration<double, milli>(end - start).count();
    cout << "Time: " << ms << " ms" << endl;
    return 0;
}