#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <vector>
#include <atomic>

using namespace std;

// Максимальный размер матрицы.
const int MAX_N = 1500;

int A[MAX_N][MAX_N];
int B[MAX_N][MAX_N];
int C[MAX_N][MAX_N];

// Атомарный флаг для старта многопоточных вычислений.
atomic<bool> start_flag(false);

// Однопоточное умножение с порядком циклов (i, j, k).
long long multiplySingleThread(int n) {
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                A[i][j] += B[i][k] * C[k][j];
            }
        }
    }
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count();
}

// Функция для одного потока: обрабатывает строки от start_row до end_row.
void multiplyRows(int start_row, int end_row, int n) {
    // Ждём разрешения от главного потока.
    while (!start_flag.load()) {
        this_thread::yield();
    }
    // Многопоточное умножение с порядком (i, k, j).
    for (int i = start_row; i < end_row; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                A[i][j] += B[i][k] * C[k][j];
            }
        }
    }
}

// Многопоточное умножение на 4 потока.
long long multiplyFourThreads(int n) {
    const int num_threads = 4;
    vector<thread> threads;
    int rows_per_thread = n / num_threads;
    int start_row = 0;
    // Создаём потоки до запуска таймера.
    for (int t = 0; t < num_threads; t++) {
        int end_row = start_row + rows_per_thread;
        // Последний поток забирает оставшиеся строки.
        if (t == num_threads - 1) {
            end_row = n;
        }
        threads.emplace_back(multiplyRows, start_row, end_row, n);
        start_row = end_row;
    }
    // Замеряем только вычисления.
    auto start = chrono::high_resolution_clock::now();
    start_flag.store(true);
    for (thread& th : threads) {
        th.join();
    }
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count();
}

// Заполняем B и C, обнуляем A перед каждым тестом.
void prepareMatrices(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 0;
            B[i][j] = 1;
            C[i][j] = 1;
        }
    }
}

int main() {
    int sizes[] = {300, 500, 800, 1500};
    int sizes_count = sizeof(sizes) / sizeof(sizes[0]);
    cout << fixed << setprecision(2);
    cout << "| n   | 1 potok (ms) | 4 potoka (ms) | Uskorenie (T1 / T4) |\n";
    cout << "|-----|--------------|---------------|---------------------|\n";
    for (int s = 0; s < sizes_count; s++) {
        int n = sizes[s];
        // Однопоточный тест.
        prepareMatrices(n);
        long long t1_us = multiplySingleThread(n);
        // Многопоточный тест.
        prepareMatrices(n);
        start_flag.store(false);
        long long t4_us = multiplyFourThreads(n);
        double t1_ms = t1_us / 1000.0;
        double t4_ms = t4_us / 1000.0;
        double speedup = t4_us > 0 ? (double)t1_us / t4_us : 0.0;
        cout << "| "
             << setw(3) << n << " | "
             << setw(12) << t1_ms << " | "
             << setw(13) << t4_ms << " | "
             << setw(19) << speedup << " |\n";
    }
    return 0;
}