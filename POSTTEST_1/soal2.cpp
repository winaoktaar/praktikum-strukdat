#include <bits/stdc++.h>
using namespace std;

int main() {
    const int R = 3, C = 3;
    int mat[R][C];

    cout << "Masukkan elemen matriks 3x3 (baris per baris):\n";
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << "mat[" << i+1 << "][" << j+1 << "] = ";
            cin >> mat[i][j];
        }
    }

    cout << "\nMatriks:\n";
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) cout << mat[i][j] << " ";
        cout << "\n";
    }

    int sumEvenRows = 0;
    for (int i = 0; i < R; ++i) {
        int rowNumber = i + 1;
        if (rowNumber % 2 == 0) { 
            for (int j = 0; j < C; ++j) sumEvenRows += mat[i][j];
        }
    }

    cout << "\nJumlah elemen pada baris genap: " << sumEvenRows << "\n";
    return 0;
}
