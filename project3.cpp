#include <iostream>
#include <vector>

using namespace std;

struct Barang {
    string kodeBrg;
    string namaBrg;
    double harga;
    int stok;
};
vector<Barang> inventaris;

void tambahBarang() {
    Barang baru;
    cout << "Masukkan kode barang: ";
    cin >> baru.kodeBrg;
    cout << "Masukkan nama barang: ";
    cin >> baru.namaBrg;
    cout << "Masukkan harga barang: ";
    cin >> baru.harga;
    while (baru.harga < 0) {
        cout << "Harga tidak boleh negatif. Masukkan harga yang benar: ";
        cin >> baru.harga;
    }
    cout << "Masukkan stok barang: ";
    cin >> baru.stok;
    while (baru.stok < 0) {
        cout << "Stok tidak boleh negatif. Masukkan stok yang benar: ";
        cin >> baru.stok;
    }
    inventaris.push_back(baru);
}

void tampilkanSemuaBarang() {
    cout << "Daftar Barang:" << endl;
    cout << "Kode\tNama\tHarga\tStok" << endl;
    for (const auto& barang : inventaris) {
        cout << barang.kodeBrg << "\t" << barang.namaBrg << "\t" << barang.harga << "\t" << barang.stok << endl;
    }
}

void cariBarangTermahal() {
    if (inventaris.empty()) {
        cout << "Inventaris kosong." << endl;
        return;
    }
    Barang* termahal = &inventaris[0];
    for (auto& barang : inventaris) {
        if (barang.harga > termahal->harga) {
            termahal = &barang;
        }
    }
    cout << "Barang Termahal:" << endl;
    cout << "Kode: " << termahal->kodeBrg << endl;
    cout << "Nama: " << termahal->namaBrg << endl;
    cout << "Harga: " << termahal->harga << endl;
    cout << "Stok: " << termahal->stok << endl;
}

void hitungTotalNilaiInventaris() {
    double total = 0;
    for (const auto& barang : inventaris) {
        total += barang.harga * barang.stok;
    }
    cout << "Total Nilai Inventaris: " << total << endl;
}

void cekRestock() {
    cout << "Barang dengan stok kurang dari 5:" << endl;
    for (const auto& barang : inventaris) {
        if (barang.stok < 5) {
            cout << "Kode: " << barang.kodeBrg << ", Nama: " << barang.namaBrg << ", Stok: " << barang.stok << endl;
        }
    }
}

void updateStok() {
    string kode;
    cout << "Masukkan kode barang yang ingin diupdate stoknya: ";
    cin >> kode;
    for (auto& barang : inventaris) {
        if (barang.kodeBrg == kode) {
            int* stokPtr = &barang.stok;
            cout << "Stok saat ini: " << *stokPtr << endl;
            cout << "Masukkan perubahan stok (positif untuk tambah, negatif untuk kurangi): ";
            int perubahan;
            cin >> perubahan;
            while (*stokPtr + perubahan < 0) {
                cout << "Perubahan stok tidak valid. Stok tidak boleh negatif. Masukkan perubahan yang benar: ";
                cin >> perubahan;
            }
            *stokPtr += perubahan;
            cout << "Stok berhasil diupdate. Stok baru: " << *stokPtr << endl;
            return;
        }
    }
    cout << "Barang dengan kode tersebut tidak ditemukan." << endl;
}

int main() {
    int pilihan;
    do {
        cout << "Menu:" << endl;
        cout << "1. Tambah Barang" << endl;
        cout << "2. Tampilkan Semua Barang" << endl;
        cout << "3. Cari Barang Termahal" << endl;
        cout << "4. Hitung Total Nilai Inventaris" << endl;
        cout << "5. Cek Restock (Stok < 5)" << endl;
        cout << "6. Update Stok" << endl;
        cout << "7. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahBarang();
                break;
            case 2:
                tampilkanSemuaBarang();
                break;
            case 3:
                cariBarangTermahal();
                break;
            case 4:
                hitungTotalNilaiInventaris();
                break;
            case 5:
                cekRestock();
                break;
            case 6:
                updateStok();
                break;
            case 7:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih menu yang benar." << endl;
        }
    } while (pilihan != 7);

    return 0;
}