#include <iostream>
#include <vector>

using namespace std;

long long ops1 = 0;
long long ops2 = 0;

int Mystery(int n) {
    int S = 0;
    for (int i=1; i<=n; ++i) {
        S += i*i;
        ops1++;
    }
    return S;
}
int MysteryMod(long long n) {
    return n*(n+1)*(2*n+1)/6;
}

double Secret(double* A, int n) {
    double minval = A[0], maxval = A[0];
    for (int i=1; i<n; i++) {
        if (A[i] < minval) minval = A[i];
        ops1++;
        if (A[i] > maxval) maxval = A[i];
        ops1++;
    }
    return maxval-minval;
}
double SecretMod(double* A, int n) {
    double minval, maxval;
    int start;
    if (n%2==1) {
        minval = maxval = A[0];
        start = 1;
    } else {
        ops2++;
        if (A[0]<A[1]) {
            minval = A[0];
            maxval = A[1];
        } else {
            minval = A[1]; 
            maxval = A[0];
        }
        start = 2;
    }
    for (int i=start; i+1<n; i+=2) {
        double small, big;
        if (A[i] < A[i + 1]) {
            small = A[i];
            big = A[i + 1];
        } else { 
            small = A[i + 1];
            big = A[i];
        }
        ops2++;
        if (small<minval) minval = small;
        ops2++; 
        if (big>maxval) maxval = big;
        ops2++; 
    }
    return maxval - minval;
}

// const int N = 500;
// bool Enigma(int A[][N]) {
//     for (int i=0; i<=N-2; i++) {
//         for (int j=i+1; j<=N-1; j++) {
//             if (A[i][j]!=A[j][i]) return false;
//             ops1++;
//         }
//     }
//     return true;
// }

// const int N = 400;
// int MatrixMultiplication(int A[][N], int B[][N]) {
//     int C[N][N];
//     for (int i=0; i<N; i++) {
//         for (int j=0; j<N; j++) {
//             C[i][j] = 0;
//             for (int k=0; k<N; k++) {
//                 C[i][j] = C[i][j]+A[i][k]*B[k][j];
//                 ops1++;
//             }
//         }
//     }
//     return *C[0];
// }
// int MatrixMultiplicationMod(int A[][N], int B[][N]) {
//     int C[N][N];
//     for (int i=0; i<N; i++) {
//         for (int j=0; j<N; j++) {
//             double sum = A[i][0]*B[0][j];
//             for (int k=1; k<N; k++) {
//                 sum += A[i][k]*B[k][j];
//                 ops2++;
//             }
//             C[i][j] = sum;
//         }
//     }
//     return *C[0];
// }

int Binary(long long n) {
    int count = 1;
    while (n>1) {
        count += 1;
        n /= 2;
        ops1++;
    }
    return count;
}
int bitsLength(long long n) {
    int b = 0;
    while (n > 0) {
        b++;
        n = n >> 1;
    }
    return b;
}


int main() {
    //1
    // int N = 1000;
    // cout << "n = " << N << endl;
    // cout << "Mystery(n) = " << Mystery(N) << endl;
    // cout << "MysteryMod(n) = " << MysteryMod(N) << endl;
    // cout << "ops = " << ops1 << endl;
    // ops1 = 0;

    //2
    // const int N = 100000;
    // double A[N];
    // for (int i=0; i<N; i++) A[i] = i*1.5;
    // cout << "n = " << N << endl;
    // cout << "Secret(A[n]) = " << Secret(A, N) << endl;
    // cout << "ops1 = " << ops1 << endl;
    // cout << "SecretMod(A[n]) = " << SecretMod(A, N) << endl;
    // cout << "ops2 = " << ops2 << endl;
    // ops1 = 0;
    // ops2 = 0;

    //3
    // int A[N][N];
    // for (int i=0; i<N; i++) {
    //     for (int j=0; j<N; j++) A[i][j] = i+j;
    // }
    // cout << "n = " << N << endl;
    // cout << "Enigma(A[n][n]) = " << Enigma(A, N) << endl;
    // cout << "ops = " << ops1 << endl;
    // ops1 = 0;
    // ops2 = 0;

    //4
    // int A[N][N], B[N][N];
    // for (int i=0; i<N; i++) {
    //     for (int j=0; j<N; j++) {
    //         A[i][j] = i+j+1;
    //         B[i][j] = i/3+j*2;
    //     }
    // }
    // cout << "n = " << N << endl;
    // cout << "MatrixMultiplication(A[n][n], B[n][n]) = " << MatrixMultiplication(A, B) << endl;
    // cout << "ops1 = " << ops1 << endl;
    // cout << "MatrixMultiplicationMod(A[n][n], B[n][n]) = " << MatrixMultiplicationMod(A, B) << endl;
    // cout << "ops2 = " << ops2 << endl;
    // ops1 = 0;
    // ops2 = 0;

    //5
    long long N = 7;
    cout << "n = " << N << endl;
    cout << "Binary(n) = " << Binary(N) << endl;
    cout << "ops = " << ops1 << endl;
    cout << "BitsLength(n) = " << bitsLength(N) << endl;

    return 0;
}