#include <iostream>
using namespace std;

int main() {
    int m = 2, n = 3;
    int A[m][n] = {
        {3, 7, 5},
        {2, 9, 4}
    };

    int maxVal = A[0][0];
    int minVal = A[0][0];
    int cari = 9;
    bool ditemukan = false;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] > maxVal) maxVal = A[i][j];
            if (A[i][j] < minVal) minVal = A[i][j];
            if (A[i][j] == cari) ditemukan = true;
        }
    }

    cout << "Nilai maksimum: " << maxVal << endl;
    cout << "Nilai minimum: " << minVal << endl;

    if (ditemukan)
        cout << "Nilai " << cari << " ditemukan dalam matriks." << endl;
    else
        cout << "Nilai " << cari << " tidak ditemukan." << endl;

    return 0;
}
