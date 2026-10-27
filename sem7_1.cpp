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

int main() {
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                A[i][j] += B[i][k] * C[i][k];
            }
        }
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