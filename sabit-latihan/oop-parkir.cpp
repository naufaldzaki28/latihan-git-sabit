#include <iostream>
using namespace std;

class Parkir {
private:
    int biaya;
    int total_detik;
    int jam, menit, detik;
    int total_jam;
    string jenis_kendaraan;

public:
    Parkir() : biaya(0), total_detik(0), jam(0), menit(0), detik(0), total_jam(0) {}

    void inputWaktu() {
        cout << "Masukkan waktu parkir dalam detik: ";
        cin >> total_detik;
    }

    void hitungWaktu() {
        jam = total_detik / 3600;
        total_detik %= 3600;
        menit = total_detik / 60;
        detik = total_detik % 60;

        total_jam = jam;
        if (menit > 0 || detik > 0) {
            total_jam += 1;
        }
    }

    void setKendaraan(int pilihan) {
        if (pilihan == 1) {
            jenis_kendaraan = "Mobil";
            biaya = (total_jam <= 1) ? 2000 : 2000 + (total_jam - 1) * 2000;
        } else if (pilihan == 2) {
            jenis_kendaraan = "Motor";
            biaya = (total_jam <= 1) ? 2000 : 2000 + (total_jam - 1) * 1000;
        }
    }

    void tampilkanHasil() const {
        cout << "Jenis kendaraan: " << jenis_kendaraan << '\n';
        cout << "Waktu parkir: " << jam << " jam " << menit << " menit " << detik << " detik\n";
        cout << "Total biaya parkir: Rp " << biaya << '\n';
    }
};

class AplikasiParkir {
public:
    void run() {
        int input, pilih;
        do {
            cout << "=== Selamat datang di parkir ===\n";
            cout << "1. Parkir\n";
            cout << "2. Keluar\n";
            cout << "Masukkan pilihan: ";
            cin >> input;

            switch (input) {
                case 1: {
                    cout << "== Silahkan pilih kendaraan ==\n";
                    cout << "1. Mobil\n";
                    cout << "2. Motor\n";
                    cout << "Masukkan pilihan: ";
                    cin >> pilih;

                    if (pilih == 1 || pilih == 2) {
                        Parkir p;
                        p.inputWaktu();
                        p.hitungWaktu();
                        p.setKendaraan(pilih);
                        p.tampilkanHasil();
                    } else {
                        cout << "Pilihan kendaraan tidak valid!\n";
                    }
                    break;
                }
                case 2:
                    cout << "== Terima kasih telah menggunakan layanan kami! ==\n";
                    break;
                default:
                    cout << "Yang anda masukkan salah!\n";
                    break;
            }
        } while (input != 2);
    }
};

int main() {
    AplikasiParkir app;
    app.run();
    return 0;
}
