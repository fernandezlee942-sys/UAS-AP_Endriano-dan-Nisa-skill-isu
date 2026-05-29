#define Fernandez_Lebih_Ganteng_Dari_Justin_Bieber true
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class minesweeper{
public:
    int mapSize;
    int bombTotal;
    int koordinatTX;
    int koordinatTY;
    bool isBlank[10][10];
    bool isBomb[10][10];
    bool isNumber[10][10];
    int bombAround[10][10];
    bool isUnlocked[10][10];


    void play(){

        //map reset
        for(int i = 0; i < mapSize; i++) {
            for(int j = 0; j < mapSize; j++) {
                isBomb[i][j] = false;
                isUnlocked[i][j] = false;
                isNumber[i][j] = false;
                bombAround[i][j] = 0;
                isBlank[i][j] = true;
            }
        }

        while(Fernandez_Lebih_Ganteng_Dari_Justin_Bieber){
            f:
            system("cls");
            makeMap(mapSize);
            d:
            cout<<"\nInput x Coordinate to guess : ";
            cin>>koordinatTX;
            if((koordinatTX>0)&&(koordinatTX<=mapSize)){

                e:
                cout<<"\nInput y Coordinate to guess : ";
                cin>>koordinatTY;
                if((koordinatTY>0)&&(koordinatTY<=mapSize)){
                    isUnlocked[koordinatTX][koordinatTY]=true;
                    goto f;
                }
                else{
                ClearInputBuffer();
                cout<<"Input should be an integer smaller than the map size\n";
                system("pause");
                goto e;

                }

            }
            else{
                ClearInputBuffer();
                cout<<"Input should be an integer smaller than the map size\n";
                system("pause");
                goto d;
            }
            
        }
    }

    void playMenu(){    
        int menu;

        cout<<"Minesweeper frfr : "<<endl;
        cout<<"1. New Game"<<endl;
        cout<<"2. Exit"<<endl;
        a:
        cout<<"Pilih Menu : ";

        while(Fernandez_Lebih_Ganteng_Dari_Justin_Bieber){
            cin>>menu;
            if (menu==1){
                system("cls");

                b:
                cout<<"Input Map Size (map should be bigger than 3 but less than 10,for 9*9 --> just type 9) : "; 
                cin>>mapSize;

                //small note, jlh bomb hrs lebih kecil dari ukuran map --> jaga2 kelupaan, persentase bom harus dibawah 20% ukuran map

                if((mapSize<=10)&&(mapSize>3)){
                    c:
                    cout<<"Input Bomb Total (the amount of bomb should be less or equal to 20% of the map size) : ";
                    cin>>bombTotal;

                    if((bombTotal<=(mapSize*mapSize)/5)&&(bombTotal>0)){
                        play();
                    }
                    
                    else{
                        ClearInputBuffer();
                        cout<<"Invalid Total Bomb, choose an  integer below the 20% of the map size\n";
                        //goddamn i fkin hate the % from c
                        system("pause");
                        goto c;
                    }                    
                }
                
                else{
                    ClearInputBuffer();
                    cout<<"Invalid map size choose an integer between 3-10\n";
                    system("pause");
                    goto b;
                }
            }
            else if (menu==2){
                cout<<"Thanks for playing!";
                break;
            }
            else{
                ClearInputBuffer();
                cout<<"Skill issue --> choose between 1 or 2\n";
                system("pause");
                goto a;
            }
        }
    }

    void ClearInputBuffer(){
        cin.clear();
        while(cin.get()!='\n'){
            continue;
        }
    }

    void makeMap(int mapSize){
        system("cls");
        
        for(int i = 0;i<mapSize;i++){
            for(int j=0;j<mapSize;j++){
                if (isUnlocked[i][j]){
                    if (isBomb[i][j]==true){
                        cout<<"B ";
                    }
                    else if (isNumber[i][j]==true){
                        cout<<bombAround[i][j];
                    }
                    //nanti buatgic kek, randomized bomb, is bomb jg dicatat pastikan g dobel isbombnya,
                    //hbs itu buat rumus buat is number (sekitar bomb) if not bomb has bomb next to it bombaround+=1; else is blank
    
                    else{
                        cout<<"* ";
                    }
                }
                else{
                    cout<<"* ";
                }
            }
            cout<<"\n"; 
        }
    }

    int randomNumGenerator(){
       return rand()%mapSize+1;
    }

    void BombCreation(){
        for(int k=0;k<bombTotal;k++){
            isBomb[randomNumGenerator()][randomNumGenerator()]=true;
            
        }
        
    }

    void BlankspaceHandler(){

    }

};


int main() {
    minesweeper inigamefrfr;
    inigamefrfr.playMenu();
    return 0;
}

// Gambaran Umum :
// Permainan berlangsung pada papan berukuran N x N (N bisa dipilih pemain, misal 4–10). Di dalam papan terdapat sejumlah bom yang ditempatkan secara acak. Pemain dapat membuka kotak atau menandai kotak yang dicurigai bom. 

// Requirements Program :
// Kelas Permainan
// Buat satu class yang menangani seluruh state permainan: papan, bom, status buka/tandai, ukuran, dan logika permainan. Jangan gunakan struct tambahan.

// Pemain bisa memilih ukuran papan dan jumlah bom sebelum mulai. Bom ditanam acak, dan setiap kotak bukan bom harus mengetahui berapa bom di sekitarnya (8 tetangga).

// Buka kotak: jika kena bom → game over, tampilkan semua bom.
// Tandai / hapus tanda: untuk mencurigai bom.
// Jika kotak yang dibuka berisi angka 0, buka otomatis area kosong di sekitarnya hingga batas angka > 0 (efek flood fill). Implementasi bisa rekursif atau iteratif.


// Pemain menang jika semua bom berhasil ditandai dengan benar (tidak boleh ada tanda di kotak aman). Bukan hanya dengan membuka semua kotak aman.

// Penghitung Waktu
// Catat waktu permainan (dalam detik) sejak papan pertama kali ditampilkan hingga permainan berakhir. Tampilkan saat menang atau kalah.

// Papan ditampilkan dengan rapi, lengkap dengan informasi jumlah bom yang belum ditandai dan waktu berjalan. Koordinat baris/kolom bisa menggunakan angka 1..N.


// Program memiliki menu sederhana: Mulai Permainan Baru, Keluar. Setelah selesai satu ronde, pemain bisa kembali ke menu.

// Constraints
// Gunakan array 2D statis dengan ukuran maksimum 10×10.
// Header yang diizinkan: <iostream>, <cstdlib>, <ctime>. Jika ingin menggunakan Header lain atau custom, silahkan hubungi Asisten Lab.

// Rekursi untuk flood fill diperbolehkan dan disarankan, tapi tetap bisa dengan loop.
// Validasi input dasar (ukuran papan, jumlah bom, koordinat) wajib dilakukan.
// Note: Pengembangan program bersifat fleksibel, sesuai dengan kemampuan.

//  i wanna sleep