#include <iostream>
using namespace std;

int main(){
    int biaya, total_detik, jam, menit, detik;
    cout << "===Selamat datang di parkir===\n";
    cout << "Masukkan waktu parkir dalam detik: "; 
    cin >> total_detik;

    jam = total_detik / 3600;
    total_detik %= 3600;
    menit = total_detik / 60;
    detik = total_detik % 60;

    int total_jam = jam;
    if (menit > 0 || detik > 0) {
        total_jam += 1;
    }

    if (total_jam <= 1) {
        biaya = 2000;
    } else {
        biaya = 2000 + (total_jam - 1) * 1000;
    }

    cout << "Waktu parkir: " << jam << " jam " << menit << " menit " << detik << " detik\n";
    cout << "Total biaya parkir: Rp " << biaya << '\n';
    return 0;
}
