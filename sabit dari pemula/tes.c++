#include <iostream>
using namespace std;

int main() {
int biaya, total_detik, jam, menit, detik, input, pilih;
do {
cout << "===Selamat datang di parkir===\n";
cout << "1. Parkir\n";
cout << "2. Keluar\n";
cout << "Masukkan pilihan: "; cin >> input;
switch (input) {
    case 1:
        cout << "==Silahkan pilih kendaraan==\n";
        cout << "1. Mobil\n";
        cout << "2. Motor\n";
        cout << "Masukkan pilihan: "; cin >> pilih;
        if (pilih == 1){
            cout << "Jenis kendaraan: Mobil\n";
            cout << "Masukkan waktu parkir dalam detik: "; cin >> total_detik;
            jam = total_detik / 3600;
            total_detik %= 3600;
            menit = total_detik /60;
            detik = total_detik %= 60;
            if(jam == 0 ||  jam == 1 && menit == 0 && detik ==  0){    
                biaya = 2000;
            } else if (jam == 1 && menit > 0 && detik > 0 || jam > 1 && menit == 0 && detik == 0){
                biaya = 2000 + (jam * 3000);
            } else {
                "Parkir tidak valid\n";
            }  
            cout << "waktu parkir: " << jam << " jam " << menit << " menit " << detik << " detik" << '\n';
            cout << "total biaya parkir: Rp " << biaya << '\n';
        }
        if (pilih == 2){
            cout << "Jenis kendaraan: Motor\n";
            cout << "Masukkan waktu parkir dalam detik: "; cin >> total_detik;
            jam = total_detik / 3600;
            total_detik %= 3600;
            menit = total_detik /60;
            detik = total_detik %= 60;
            if(jam == 0 ||  jam == 1 && menit == 0 && detik ==  0){    
                biaya = 1000;
            } else if (jam == 1 && menit > 0 && detik > 0 || jam > 1 && menit == 0 && detik == 0){
                biaya = 1000 + (jam * 2000);
            } else {
                "Parkir tidak valid\n"; 
            }  
            cout << "waktu parkir: " << jam << " jam " << menit << " menit " << detik << " detik" << '\n';
            cout << "total biaya parkir: Rp " << biaya << '\n';
        }
    break;
    case 2:
            cout << "==Terima kasih telah menggunakan layanan kami!==\n";
    break;
    default:
            cout << "Yang anda masukkan salah!\n";
    break;
        }
    } while (input != 2);

return 0;
}