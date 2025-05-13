#include <iostream>
using namespace std;

int main(){
    int biaya, total_detik, jam, menit, detik;
    cout << "===Selamat datang di parkir===\n";
    cout << "Masukkan waktu parkir dalam detik: "; cin >> total_detik;
    jam = total_detik /3600;
    total_detik %= 3600;
    menit = total_detik / 60;
    detik = total_detik % 60;

    if (jam == 0 || (jam == 1 && menit == 0 && detik == 0)){
        biaya = 2000;
    } else if (jam == 1 && menit > 0 && detik > 0 || jam > 1 && menit == 0 && detik == 0){
        biaya = 2000 + (jam * 3000);
    } else {
        cout << "Parkir tidak valid\n";
    }
    cout << "waktu parkir: " << jam << " jam " << menit << " menit " << detik << " detik" << '\n';
    cout << "total biaya parkir: Rp " << biaya << '\n';
    return 0;
}