s#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

// Fungsi untuk mengubah string "hh:mm:ss" ke total detik
int waktuKeDetik(string waktu) {
    int h, m, s;
    char c1, c2;
    stringstream ss(waktu);
    ss >> h >> c1 >> m >> c2 >> s;
    return h * 3600 + m * 60 + s;
}

// Fungsi untuk menghitung durasi antara dua waktu
string durasiWaktu(string start, string end) {
    int detikAwal = waktuKeDetik(start);
    int detikAkhir = waktuKeDetik(end);

    int selisih = detikAkhir - detikAwal;
    if (selisih < 0) { // Lewat tengah malam
        selisih += 24 * 3600;
    }

    int hh = selisih / 3600;
    selisih %= 3600;
    int mm = selisih / 60;
    int ss = selisih % 60;

    stringstream hasil;
    hasil << setw(2) << setfill('0') << hh << ":"
          << setw(2) << setfill('0') << mm << ":"
          << setw(2) << setfill('0') << ss;
    return hasil.str();
}

int main() {
    string waktu1, waktu2;
    cout << "Masukkan waktu awal (hh:mm:ss): ";
    cin >> waktu1;
    cout << "Masukkan waktu akhir (hh:mm:ss): ";
    cin >> waktu2;

    cout << "Durasi = " << durasiWaktu(waktu1, waktu2) << endl;
    return 0;
}
