#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    string daftarNegara[] = {"norway", "oman", "brunei", "indonesia", "jepang", "korea", "inggris"};
    int jumlahNegara = 7;
    int skor = 0;
    char mainLagi;

    do {
        string jawaban = daftarNegara[rand() % jumlahNegara];
        string soal = jawaban;

        for (int i = 0; i < soal.length(); i++) {
            if (rand() % 2 == 0) {
                soal[i] = '_';
            }
        }

        if (soal == jawaban) {
            int indexAcak = rand() % soal.length();
            soal[indexAcak] = '_';
        }

        if (soal == string(soal.length(), '_')) {
            int indexAcak = rand() % soal.length();
            soal[indexAcak] = jawaban[indexAcak]; 
        }

        cout << "\nTebak negara: " << soal << endl;
        cout << "Negara apakah yang dimaksud? ";
        string tebakan;
        cin >> tebakan;

        for (int i = 0; i < tebakan.length(); i++) {
            tebakan[i] = tolower(tebakan[i]);
        }

        if (tebakan == jawaban) {
            cout << "Selamat! Anda benar." << endl;
            skor++;
        } else {
            cout << "Maaf, jawaban Anda salah. Coba lagi." << endl;
        }

        cout << "Skor Anda: " << skor << endl;

        do {
            cout << "Ingin bermain lagi? (y/n): ";
            cin >> mainLagi;
            mainLagi = tolower(mainLagi); 

            if (mainLagi != 'y' && mainLagi != 'n') {
                cout << "Input tidak valid! Silakan masukkan 'y' atau 'n'." << endl;
            }
        } while (mainLagi != 'y' && mainLagi != 'n');

    } while (mainLagi == 'y');

    cout << "\nGame Selesai :D\n";

    return 0;
}