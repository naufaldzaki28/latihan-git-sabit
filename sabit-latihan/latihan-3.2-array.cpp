#include <iostream>
using namespace std;

int main() {
    int m = 2, n = 3;
    int a[m][n] = {
        {3, 7, 5},
        {2, 9, 4}
    };
    int max = a[0][0];
    int min = a[0][0];
    int cari = 5;
    bool ditemukan = false;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] > max) max = a[i][j];
            if (a[i][j] < min) min = a[i][j];
            if (a[i][j] == cari) ditemukan = true;
        }
    }
    cout << "Nilai maksimum: " << max << endl;
    cout << "Nilai minimum: " << min << endl;
    if (ditemukan)
        cout << "Nilai " << cari << " ditemukan dalam matriks." << endl;
    else
        cout << "Nilai " << cari << " tidak ditemukan." << endl;
    return 0;
}
