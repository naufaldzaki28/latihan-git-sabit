#include <iostream>
using namespace std;

int main() {
    int biaya, total_detik, jam, menit, detik, input, pilih;
    do {
        cout << "===Selamat datang di parkir===\n";
        cout << "1. Parkir\n";
        cout << "2. Keluar\n";
        cout << "Masukkan pilihan: "; 
        cin >> input;

        switch (input) {
            case 1:
                cout << "==Silahkan pilih kendaraan==\n";
                cout << "1. Mobil\n";
                cout << "2. Motor\n";
                cout << "Masukkan pilihan: "; 
                cin >> pilih;

                if (pilih == 1 || pilih == 2) {
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

                    if (pilih == 1) { // Mobil
                        cout << "Jenis kendaraan: Mobil\n";
                        biaya = (total_jam <= 1) ? 2000 : 2000 + (total_jam - 1) * 2000;
                    } else { // Motor
                        cout << "Jenis kendaraan: Motor\n";
                        biaya = (total_jam <= 1) ? 2000 : 2000 + (total_jam - 1) * 1000;
                    }

                    cout << "Waktu parkir: " << jam << " jam " << menit << " menit " << detik << " detik\n";
                    cout << "Total biaya parkir: Rp " << biaya << '\n';
                } else {
                    cout << "Pilihan kendaraan tidak valid!\n";
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
