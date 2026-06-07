#include <iostream>
#include "TebakKata.h"

using namespace std;

int main() {
    srand(time(0)); //supaya kata yang dipilih acak setiap kali program dijalankan
    char mainLagi;
    string namaPemain;

    system("cls");
    cout << "========================================\n";
    cout << "|    HALO! SELAMAT DATANG DI GAME      |\n";
    cout << "========================================\n\n";
    cout << "Siapa namamu? : ";
    getline(cin, namaPemain);

    do {
        KataGame game;
        char tebakanSalah[26];
        int jumlahSalah = 0;
        int maxNyawa = 0;
        int pengaliSkor = 0;

        int pilihan;
        do {
            system("cls");
            cout << "========================================\n";
            cout << "|       PILIH TINGKAT KESULITAN        |\n";
            cout << "========================================\n";
            cout << "  1. Easy   (8 Nyawa)\n";
            cout << "  2. Medium (6 Nyawa)\n";
            cout << "  3. Hard   (4 Nyawa)\n";
            cout << "----------------------------------------\n";
            cout << "Pilihanmu (1/2/3): ";
            cin >> pilihan;
            
            if (pilihan == 1) { maxNyawa = 8; pengaliSkor = 10; }
            else if (pilihan == 2) { maxNyawa = 6; pengaliSkor = 20; }
            else if (pilihan == 3) { maxNyawa = 4; pengaliSkor = 30; }
            else { cout << "Pilihan tidak valid!\n"; system("pause"); }
        } while (pilihan < 1 || pilihan > 3);

        inisialisasiGame(&game, maxNyawa); 
        string pesanSistem = "Semoga berhasil, " + namaPemain + "!";

        while (game.sisaNyawa > 0 && game.statusTebakan != game.kataAsli) {
            tampilkanUI(&game, tebakanSalah, jumlahSalah, pesanSistem);
            pesanSistem = ""; 

            cout << "Masukkan tebakan huruf: ";
            char input;
            cin >> input;

            if (input == '?') {
                if (gunakanHint(&game)) pesanSistem = "Hint digunakan! (-1 Nyawa)";
                else pesanSistem = "Hint gagal! (Nyawa kamu terlalu sedikit)";
                continue;
            }

            bool isDuplikat, isValid;
            prosesTebakan(&game, input, tebakanSalah, &jumlahSalah, &isDuplikat, &isValid); 

            if (!isValid) {
                pesanSistem = "Tolong masukkan huruf alphabet saja!";
            } else if (isDuplikat) {
                pesanSistem = "Huruf sudah ditebak! Coba huruf lain.";
            } else {
                pesanSistem = "Tebakan diterima.";
            }
        }

        if (game.sisaNyawa <= 0) {
            tampilkanUI(&game, tebakanSalah, jumlahSalah, "GAME OVER! Nyawa kamu habis.");
            cout << "\n--- YAH, KAMU KALAH! ---\n";
            cout << "Kata rahasia yang benar adalah: " << game.kataAsli << "\n";
            cout << "\nTekan Enter untuk kembali ke menu...";
            cin.ignore(1000, '\n');
            cin.get();
        } else {
            tampilkanUI(&game, tebakanSalah, jumlahSalah, "PERMAINAN SELESAI!");
            int skor = (game.kataAsli.length() * 10) + (game.sisaNyawa * pengaliSkor);
            cout << "\n+++ SELAMAT KAMU MENANG! +++\n";
            cout << "Skor kamu: " << skor << "\n";
            updateLeaderboard(namaPemain, skor);
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore(1000, '\n');
            cin.get();
        }

        tampilkanLeaderboard();

        cout << "Apakah Anda ingin bermain lagi? (Y/N): ";
        cin >> mainLagi;
        mainLagi = toupper(mainLagi);

    } while (mainLagi == 'Y' || mainLagi == 'y');

    cout << "\nTerima kasih sudah bermain! Sampai jumpa.\n";
    return 0;
}
