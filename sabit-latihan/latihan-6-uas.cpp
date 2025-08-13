#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// ================= Class User =================
class User {
public:
    string username, password, role;

    User() {}
    User(string uname, string pass, string r) : username(uname), password(pass), role(r) {}

    void tampilkanProfil() {
        cout << "Username : " << username << endl;
        cout << "Role     : " << role << endl;
    }
};

// ================= Class Product =================
class Product {
public:
    string nama;
    double harga;
    int stok;

    Product() {}
    Product(string n, double h, int s) : nama(n), harga(h), stok(s) {}

    void tampilkanProduk() {
        cout << "Nama  : " << nama << endl;
        cout << "Harga : " << harga << endl;
        cout << "Stok  : " << stok << endl;
    }
};

// ================= Class Transaction =================
class Transaction {
public:
    string namaProduk;
    int jumlah;
    double total;

    Transaction() {}
    Transaction(string np, int j, double t) : namaProduk(np), jumlah(j), total(t) {}

    void simpanTransaksiKeFile(const string& username) {
        ofstream file("transaksi.txt", ios::app);
        file << username << endl;
        file << namaProduk << endl;
        file << jumlah << endl;
        file << total << endl;
        file << "-----------------------------" << endl;
        file.close();
    }
};

// ================= Class SopiSell =================
class SopiSell {
private:
    User currentUser;
    vector<Product> daftarProduk;

public:
    void start() {
        int pilih;
        do {
            cout << "\n=== Menu Utama ===\n";
            cout << "1. Registrasi\n";
            cout << "2. Login\n";
            cout << "3. Keluar\n";
            cout << "Pilih: ";
            cin >> pilih;

            switch (pilih) {
                case 1: registrasi(); break;
                case 2: login(); break;
                case 3: cout << "Terima kasih telah menggunakan Sopi Sell!\n"; return;
                default: cout << "Pilihan tidak valid!\n";
            }
        } while (true);
    }

    void registrasi() {
        string uname, pass, role;
        cout << "\n=== Registrasi ===\n";
        cout << "Masukkan username: "; cin >> uname;
        cout << "Masukkan password: "; cin >> pass;
        cout << "Role (admin/customer): "; cin >> role;

        ofstream file("akun.txt", ios::app);
        file << uname << endl;
        file << pass << endl;
        file << role << endl;
        file << "-----------------------------" << endl;
        file.close();

        cout << "Registrasi berhasil!\n";
    }

    void login() {
        string uname, pass;
        cout << "\n=== Login ===\n";
        cout << "Username: "; cin >> uname;
        cout << "Password: "; cin >> pass;

        ifstream file("akun.txt");
        string u, p, r, garis;
        bool ditemukan = false;

        while (file >> u >> p >> r) {
            file.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(file, garis); // baca pembatas
            if (u == uname && p == pass) {
                currentUser = User(u, p, r);
                ditemukan = true;
                break;
            }
        }
        file.close();

        if (ditemukan) {
            cout << "Login berhasil! Selamat datang, " << currentUser.username << "\n";
            if (currentUser.role == "admin") menuAdmin();
            else menuCustomer();
        } else {
            cout << "Login gagal! Username atau password salah.\n";
        }
    }

    void menuAdmin() {
        int pilih;
        do {
            cout << "\n=== Menu Admin ===\n";
            cout << "1. Tambah Produk\n";
            cout << "2. Lihat Produk\n";
            cout << "3. Logout\n";
            cout << "Pilih: ";
            cin >> pilih;

            switch (pilih) {
                case 1: tambahProduk(); break;
                case 2: lihatProduk(); break;
                case 3: return;
                default: cout << "Pilihan tidak valid!\n";
            }
        } while (true);
    }

    void menuCustomer() {
        int pilih;
        do {
            cout << "\n=== Menu Customer ===\n";
            cout << "1. Lihat Produk\n";
            cout << "2. Beli Produk\n";
            cout << "3. Logout\n";
            cout << "Pilih: ";
            cin >> pilih;

            switch (pilih) {
                case 1: lihatProduk(); break;
                case 2: beliProduk(); break;
                case 3: return;
                default: cout << "Pilihan tidak valid!\n";
            }
        } while (true);
    }

    void tambahProduk() {
        string nama;
        double harga;
        int stok;
        cout << "Masukkan nama produk: "; cin >> nama;
        cout << "Masukkan harga: "; cin >> harga;
        cout << "Masukkan stok: "; cin >> stok;

        daftarProduk.push_back(Product(nama, harga, stok));
        cout << "Produk berhasil ditambahkan!\n";
    }

    void lihatProduk() {
        cout << "\n=== Daftar Produk ===\n";
        if (daftarProduk.empty()) {
            cout << "Belum ada produk.\n";
            return;
        }
        for (size_t i = 0; i < daftarProduk.size(); i++) {
            cout << i + 1 << ". ";
            daftarProduk[i].tampilkanProduk();
            cout << endl;
        }
    }

    void beliProduk() {
        lihatProduk();
        if (daftarProduk.empty()) return;

        int pilih, jumlah;
        cout << "Pilih nomor produk: "; cin >> pilih;
        if (pilih < 1 || pilih > daftarProduk.size()) {
            cout << "Produk tidak ditemukan.\n";
            return;
        }
        cout << "Masukkan jumlah beli: "; cin >> jumlah;

        Product &p = daftarProduk[pilih - 1];
        if (jumlah > p.stok) {
            cout << "Stok tidak mencukupi!\n";
            return;
        }

        double total = jumlah * p.harga;
        p.stok -= jumlah;

        Transaction t(p.nama, jumlah, total);
        t.simpanTransaksiKeFile(currentUser.username);

        cout << "Pembelian berhasil! Total harga: " << total << endl;
    }
};

// ================= Main =================
int main() {
    SopiSell app;
    app.start();
    return 0;
}
