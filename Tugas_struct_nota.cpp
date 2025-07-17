#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Stok {
    string merk, HD, pros, MB, ps, vga, cas, monitor, key, mou, speak, garansi;
    double hrg = 0, tipe = 0, ram = 0;
};

struct Pembeli {
    string nama, alamat, hp;
};

struct Belanjaan {
    string nama_barang;
    int jumlah;
    double harga;
};

int main() {
    Pembeli cus;
    Stok stoks;
    vector<Belanjaan> belanjaan;
    string tgl_beli;
    long total_hrg = 0, bayar = 0, kembalian = 0;
    int nota = 0, kode = 0, jwb = 0;
    bool lanjut = true;

    while (lanjut) {
        cout << "\n===== TOKO KOMPUTER KITA =====\n\n";
        cout << "Nota Pembelian : "; cin >> nota;
        cout << "Tgl Pembelian  : "; cin >> tgl_beli;
        cout << "Nama Pembeli   : "; cin >> cus.nama;
        cout << "Alamat Pembeli : "; cin >> cus.alamat;
        cout << "Telepon        : "; cin >> cus.hp;

        cout << "\nJenis Pembelian [1. Laptop | 2. PC]: "; cin >> kode;
        Belanjaan beli;

        if (kode == 1) {
            cout << "Merk     : "; cin >> stoks.merk;
            cout << "Tipe     : "; cin >> stoks.tipe;
            cout << "Garansi  : "; cin >> stoks.garansi;
            cout << "Quantity : "; cin >> beli.jumlah;
            cout << "Harga    : "; cin >> stoks.hrg;

            total_hrg = beli.jumlah * stoks.hrg;

            cout << "\nMasukkan jumlah pembayaran: ";
            cin >> bayar;
            kembalian = bayar - total_hrg;

            beli.nama_barang = stoks.merk;
            beli.harga = stoks.hrg;
            belanjaan.push_back(beli);
        }
        else if (kode == 2) {
            cout << "Hardisk   : "; cin >> stoks.HD;
            cout << "Prosesor  : "; cin >> stoks.pros;
            cout << "MainBoard : "; cin >> stoks.MB;
            cout << "RAM (GB)  : "; cin >> stoks.ram;
            cout << "PSU       : "; cin >> stoks.ps;
            cout << "VGA Card  : "; cin >> stoks.vga;
            cout << "Cassing   : "; cin >> stoks.cas;
            cout << "Monitor   : "; cin >> stoks.monitor;
            cout << "Keyboard  : "; cin >> stoks.key;
            cout << "Mouse     : "; cin >> stoks.mou;
            cout << "Speaker   : "; cin >> stoks.speak;
            cout << "Garansi   : "; cin >> stoks.garansi;

            // Harga asumsi sederhana
            stoks.hrg = 5000000 + (stoks.ram * 100000); // Bisa dikembangkan

            total_hrg = stoks.hrg;
            cout << "\nHarga total rakitan PC: Rp " << stoks.hrg << endl;
            cout << "Masukkan jumlah pembayaran: ";
            cin >> bayar;
            kembalian = bayar - total_hrg;

            beli.nama_barang = "Rakitan PC Custom";
            beli.jumlah = 1;
            beli.harga = stoks.hrg;
            belanjaan.push_back(beli);
        }
        else {
            cout << "Kode tidak valid!\n";
            continue;
        }

        // Rincian Belanja
        cout << "\n======= RINCIAN BELANJA =======\n";
        for (size_t i = 0; i < belanjaan.size(); ++i) {
            cout << i + 1 << ". " << belanjaan[i].nama_barang
                 << " x " << belanjaan[i].jumlah
                 << " = Rp " << belanjaan[i].jumlah * belanjaan[i].harga << endl;
        }

        cout << "Total Harga   : Rp " << total_hrg << endl;
        cout << "Uang Bayar    : Rp " << bayar << endl;
        cout << "Uang Kembalian: Rp " << kembalian << endl;

        cout << "\nMau beli lagi? [1 = Ya, 2 = Tidak]: ";
        cin >> jwb;
        if (jwb != 1) {
            lanjut = false;
            cout << "\nTerima kasih sudah berbelanja di toko kami!\n";
        }

        // Kosongkan data belanja jika ingin reset setiap loop
        belanjaan.clear();
    }

    return 0;
}
