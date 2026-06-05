#ifndef TEBAKKATA_H
#define TEBAKKATA_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

struct KataGame {
    string kataAsli;
    string statusTebakan;
    int sisaNyawa;
    int maxNyawa;
};

struct ScoreBoard {
    string nama;
    int skor;
};

const string BANK_KATA[15] = {
    "ALGORITMA", "KOMPUTER", "PEMROGRAMAN", "POINTER", "STRUKTUR",
    "DATABASE", "JARINGAN", "INTERNET", "TERMINAL", "KEYBOARD",
    "MONITOR", "PROSESOR", "SOFTWARE", "HARDWARE", "DEBUGGING"
};

ScoreBoard leaderboard[5] = {
    {"Kosong", 0}, {"Kosong", 0}, {"Kosong", 0}, {"Kosong", 0}, {"Kosong", 0}
};

void inisialisasiGame(KataGame* game, int maxNyawa) {
    game->kataAsli = BANK_KATA[rand() % 15];
    game->sisaNyawa = maxNyawa;
    game->maxNyawa = maxNyawa;

    game->statusTebakan = "";
    for (size_t i = 0; i < game->kataAsli.length(); i++) {
        game->statusTebakan += "_";
    }

    int indeksAcak = rand() % game->kataAsli.length();
    char hurufBonus = game->kataAsli[indeksAcak];

    for (size_t i = 0; i < game->kataAsli.length(); i++) {
        if (game->kataAsli[i] == hurufBonus) {
            game->statusTebakan[i] = hurufBonus;
        }
    }
}

void prosesTebakan(KataGame* game, char tebakan, char tebakanSalah[], int* jumlahSalah, bool* isDuplikat, bool* isValidChar) {
    *isDuplikat = false;
    *isValidChar = true;
    
    if (!isalpha(tebakan)) {
        *isValidChar = false;
        return;
    }
    
    tebakan = toupper(tebakan); 

    for (char c : game->statusTebakan) {
        if (c == tebakan) { *isDuplikat = true; return; }
    }

    for (int i = 0; i < *jumlahSalah; i++) {
        if (tebakanSalah[i] == tebakan) { *isDuplikat = true; return; }
    }

    bool tebakanBenar = false;
    for (size_t i = 0; i < game->kataAsli.length(); i++) {
        if (game->kataAsli[i] == tebakan) {
            game->statusTebakan[i] = tebakan; 
            tebakanBenar = true;
        }
    }

    if (!tebakanBenar) {
        tebakanSalah[*jumlahSalah] = tebakan;
        (*jumlahSalah)++;
        game->sisaNyawa--;
    }
}

bool gunakanHint(KataGame* game) {
    if (game->sisaNyawa <= 1) return false; 

    for (size_t i = 0; i < game->statusTebakan.length(); i++) {
        if (game->statusTebakan[i] == '_') { 
            char target = game->kataAsli[i];
            
            for (size_t j = 0; j < game->kataAsli.length(); j++) {
                if (game->kataAsli[j] == target) {
                    game->statusTebakan[j] = target;
                }
            }
            game->sisaNyawa--; 
            return true;
        }
    }
    return false;
}

void updateLeaderboard(string nama, int skorBaru) {
    for (int i = 0; i < 5; i++) {
        if (skorBaru > leaderboard[i].skor) {
            for (int j = 4; j > i; j--) {
                leaderboard[j] = leaderboard[j-1];
            }
            leaderboard[i].nama = nama;
            leaderboard[i].skor = skorBaru;
            break;
        }
    }
}

void tampilkanUI(const KataGame* game, const char tebakanSalah[], int jumlahSalah, string pesan) {
    system("cls");
    cout << "========================================\n";
    cout << "|          GAME TEBAK KATA CLI         |\n";
    cout << "========================================\n\n";
    
    int nyawaHilang = game->maxNyawa - game->sisaNyawa;
    int indexArt = (nyawaHilang * 8) / game->maxNyawa;
    if (indexArt > 8) indexArt = 8;
    if (indexArt < 0) indexArt = 0;
 
    cout << "Kata    : ";
    for (char c : game->statusTebakan) {
        if (c == '_') cout << "_ ";
        else cout << (char)tolower(c) << " ";
    }
    cout << "\nPanjang : " << game->kataAsli.length() << " huruf\n\n";
    
    cout << "> Nyawa : ";
    for(int i = 0; i < game->sisaNyawa; i++) cout << "O "; 
    cout << "(" << game->sisaNyawa << "/" << game->maxNyawa << ")\n";

    cout << "> Salah : ";
    for (int i = 0; i < jumlahSalah; i++) {
        cout << tebakanSalah[i] << " ";
    }
    cout << "\n> Hint  : Ketik '?' (-1 Nyawa)\n\n";
    
    cout << "----------------------------------------\n";
    if (pesan != "") cout << "INFO: " << pesan << "\n";
    else cout << "INFO: -\n";
    cout << "----------------------------------------\n\n";
}

void tampilkanLeaderboard() {
    cout << "\n=== TOP 5 LEADERBOARD ===\n";
    for(int i = 0; i < 5; i++) {
        cout << i+1 << ". " << leaderboard[i].nama << " - " << leaderboard[i].skor << " Poin\n";
    }
    cout << "=========================\n\n";
}

#endif
