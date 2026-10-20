#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

int nod1(int n, int m) {
    if (n == 0) return m;
    return nod1(m % n, n);
}

int nod2(int n, int m) {
    int t = n>m ? m : n;
    while (m%t==0) {
        if (n%t==0) return t;
        t--;
    }
    return 1;
}

int nod3(int m, int n) {
    int res = 1;
    for (int d = 2; d <= m && d <= n; ++d) {
        while (m % d == 0 && n % d == 0) {
            res *= d;
            m /= d;
            n /= d;
        }
    }
    return res;
}

int main() {
    int m, n;
    cout << "Enter natural m and n:\n";
    cin >> m;
    cin >> n;
    vector<pair<int, int>> testPairs = {
        {m, n},
        {1, 1},   // тривиальный случай
        {1, 10},  // одно число — делитель другого
        {2, 4},   // кратные числа
        {3, 5},   // последовательные числа Фибоначчи (много шагов)
        {5, 8},   // ещё пара Фибоначчи
        {6, 9},   // общий делитель > 1
        {7, 10},  // взаимно простые
        {4, 6},   // общий делитель
        {10, 10}  // одинаковые числа
    };
    const int RUNS = 10;
    double total1 = 0.0, total2 = 0.0, total3 = 0.0;
    for (int x = 0; x<RUNS; x++) {
        for (int r = 0; r<RUNS; r++) {
            auto start = chrono::steady_clock::now();
            nod1(testPairs[x].first, testPairs[x].second);
            volatile int result = 0;
            for (int i = 0; i < 1000; ++i) {
                result += i*2;
            }
            auto end = chrono::steady_clock::now();
            double ms = chrono::duration<double, milli>(end-start).count();
            total1 += ms;
        }
        for (int r = 0; r<RUNS; r++) {
            auto start = chrono::steady_clock::now();
            nod2(testPairs[x].first, testPairs[x].second);
            volatile int result = 0;
            for (int i = 0; i < 1000; ++i) {
                result += i*2;
            }
            auto end = chrono::steady_clock::now();
            double ms = chrono::duration<double, milli>(end-start).count();
            total2 += ms;
        }
        for (int r = 0; r<RUNS; r++) {
            auto start = chrono::steady_clock::now();
            nod3(testPairs[x].first, testPairs[x].second);
            volatile int result = 0;
            for (int i = 0; i < 1000; ++i) {
                result += i*2;
            }
            auto end = chrono::steady_clock::now();
            double ms = chrono::duration<double, milli>(end-start).count();
            total3 += ms;
        }
    }
    cout << "The average execution time of the Euclidean algorithm: " << total1/RUNS << "ms" << endl;
    cout << "The average execution time of the sequential translation algorithm: " << total2/RUNS << "ms" << endl;
    cout << "The average execution time of the algorithm for factoring numbers into prime factors: " << total3/RUNS << "ms" << endl;
    return 0;
}