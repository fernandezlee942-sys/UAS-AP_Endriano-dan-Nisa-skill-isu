    #include <iostream>
    #include <ctime>
    #include <vector>
    using namespace std;

    struct Kendaraan
    {
        string plat;
        string merek;
        string warna;
        time_t waktumasuk;
    };

   void opsisatu(vector<Kendaraan> &mobil)
{
    int tambah;

    cout << "Masukkan jumlah mobil yang akan diparkirkan : ";
    cin >> tambah;
    cin.ignore();

    if (mobil.size() + tambah > 20)
    {
        cout << "Maaf, parkiran hanya dapat memuat 20 mobil!" << endl;
        cin.ignore();
        return;
    }

    for (int i = 0; i < tambah; i++)
    {
        Kendaraan jumlahMobil;

        cout << "\nMobil ke-" << mobil.size() + 1 << endl;

        cout << "Masukkan plat mobil  : ";
        getline(cin, jumlahMobil.plat);

        cout << "Masukkan merk mobil  : ";
        getline(cin, jumlahMobil.merek);

        cout << "Masukkan warna mobil : ";
        getline(cin, jumlahMobil.warna);

        jumlahMobil.waktumasuk = time(0);

        mobil.push_back(jumlahMobil);
    }

    getchar();
};

void opsidua(vector<Kendaraan> &mobil)
{
    system("cls");

    Kendaraan *ptr;

    cout << "DAFTAR MOBIL YANG SUDAH TERPARKIR : "
         << "\n====================================================\n\n";
         cin.ignore();

    for (int i = 0; i < mobil.size(); i++)
    {
        ptr = &mobil[i];

        time_t sekarang = time(0);

        int totalDetik = difftime(sekarang, ptr -> waktumasuk);

        int jam = totalDetik / 3600;
        int menit = (totalDetik % 3600) / 60;
        int detik = totalDetik % 60;

        cout << "Mobil ke-" << i + 1 << endl;
        cout << "Plat mobil  : " << ptr -> plat << endl;
        cout << "Merk mobil  : " << ptr -> merek << endl;
        cout << "Warna mobil : " << ptr -> warna << endl;

        cout << "Waktu parkir : "
             << jam << " jam "
             << menit << " menit "
             << detik << " detik\n";

        cout << "\n====================================================\n\n";
    }
    getchar();

}

void opsitiga(vector<Kendaraan> &mobil)
{
    string bayar;
    bool ditemukan = false;

    cin.ignore();

    cout << "DAFTAR MOBIL YANG SUDAH TERPARKIR : "
         << "\n====================================================\n\n";

    for (int i = 0; i < mobil.size(); i++)
    {
        time_t sekarang = time(0);

        int totalDetik = difftime(sekarang, mobil[i].waktumasuk);

        int jam = totalDetik / 3600;
        int menit = (totalDetik % 3600) / 60;
        int detik = totalDetik % 60;

        cout << "Mobil ke-" << i + 1 << endl;
        cout << "Plat mobil  : " << mobil[i].plat << endl;
        cout << "Merk mobil  : " << mobil[i].merek << endl;
        cout << "Warna mobil : " << mobil[i].warna << endl;

        cout << "Waktu parkir : "
             << jam << " jam "
             << menit << " menit "
             << detik << " detik\n";

        cout << "\n====================================================\n\n";
    };

    do {
    cout << "Masukkan plat mobil yang ingin dibayar : ";
    getline(cin, bayar);

    for (int i = 0; i < mobil.size(); i++)
    {
        if (bayar == mobil[i].plat)
        {
            ditemukan = true;

            time_t sekarang = time(0);

            int totalDetik =
                difftime(sekarang, mobil[i].waktumasuk);

            int totalBiaya = totalDetik * 8;

            cout << "\nB I A Y A P A R K I R : Rp " << totalBiaya << endl;
            mobil.erase(mobil.begin() + i);

            break;
        }
    }

    if (!ditemukan)
    {
        cout << "\nPLAT TIDAK DITEMUKAN!" << endl;
    }
}
while (!ditemukan);
    getchar();
}

    struct Petugas
    {
        string nama;
        string id;
    };

    struct Opsi
    {
        int pilihan;
    };

    int main()
    {
        Petugas petugas;
        Opsi opsi;
        vector<Kendaraan> Mobil;

        system("cls");

        cout << "\n=======================================================\n"
            << "--------------S E L A M A T   D A T A N G--------------\n"
            << "              DI PORTAL PARKIR KHUSUS MOBIL\n"
            << "                      MALL PRIENAL"
            << "\n=======================================================\n"
            << "\nKami Senang Anda Telah Hadir."
            << "\nSebelum melanjutkan, silahkan masukkan informasi anda yang akan bertugas hari ini."
            << "\n"
            << "\nMasukkan Nama: ";
        cin >> petugas.nama;

        cout << "Masukkan ID: ";
        cin >> petugas.id;

        system("cls");

        do
        {
            cout << "\n==============================================================\n"
                << "Nama Petugas: " << petugas.nama
                << "\nID Petugas: " << petugas.id
                << "\n"
                << "\n               TERIMA KASIH ATAS KERJASAMANYA !\n"
                << "---------------S E L A M A T    B E R T U G A S---------------"
                << "\n==============================================================\n"
                << "\n"
                << "\n"
                << "Silahkan Input opsi berikut dalam bentuk angka."
                << "\n1. Tambahkan Daftar Kendaraan"
                << "\n2. Tampilkan Daftar Kendaraan"
                << "\n3. Pembayaran"
                << "\n4. Keluar Program"
                << "\nMasukkan opsi: ";
            cin >> opsi.pilihan;
            
            switch (opsi.pilihan)
            {
            case 1:
                opsisatu(Mobil);
                break;
            
            case 2:
                opsidua(Mobil);
                break;

            case 3:
                opsitiga(Mobil);
                break;

            case 4:
                return 0;

            default:
                cout << "Default";
                break;
            }
        } while (opsi.pilihan != 4);
        return 0;
    }