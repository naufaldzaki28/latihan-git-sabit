#include <iostream>
using namespace std;

void prosedurJumlahNGenap(int N) {
    if (N <= 0) {
        cout << "N harus bilangan positif (>0).\n";
        return;
    }

    long long jumlah = 1LL * N * (N - 1);

    cout << "Deret " << N << " bilangan genap pertama: ";
    for (int i = 0; i < N; ++i) {
        cout << 2 * i;
        if (i != N - 1) cout << ", ";
    }
    cout << '\n';
    cout << "Jumlah = " << jumlah << '\n';
}

int main() {
    int N;
    cout << "Masukkan N (jumlah bilangan genap pertama yang ingin ditampilkan): ";
    if (!(cin >> N)) {
        cout << "Input tidak valid.\n";
        return 0;
    }

    prosedurJumlahNGenap(N);
    return 0;
}
