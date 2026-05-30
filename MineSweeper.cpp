// (currently the input method use in this whole program only stops user from typing random bullshit like string in the input --> you can still input float like 1.2 without any problems but try doing it with smtg like 1.232345342, the program itself still works normally but you'll trigger the safety mechanism added to the next cin so embrace for the impact, as for why I didnt make it so user cant input float, I'm too deep into this shit, wished I noticed it much earlier. If you input smtg like 1.2332342 I assume that its not likely ur trying to play the game normally but just trying to find a bug or 2 --> dev note: sorry for the impoliteness not quite used to polite words in english)








//i use label when im too lazy to think whether the right syntax is continue or break dont judge me its just tht much easier

// i've realized it midway but i could've just make the clearinputbuffer into a function that took string parameter(the error name) but apparently im too lazy to change it now


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
    bool isFlagged[10][10];
    string gameResult;

    void play(){

        //map reset
        for(int j = 0; j < mapSize; j++) {
            for(int i = 0; i < mapSize; i++) {
                isBomb[i][j] = false;
                isUnlocked[i][j] = false;
                isNumber[i][j] = false;
                bombAround[i][j] = 0;
                isBlank[i][j] = true;
                isFlagged[i][j] = false;  
            }
        }
        
        
        for(int j = 0; j < mapSize; j++) {
            for(int i = 0; i < mapSize; i++) {
                isBomb[i][j] = false;
                isUnlocked[i][j] = true;
                isNumber[i][j] = false;
                bombAround[i][j] = 0;
                isBlank[i][j] = true;
            }
        }
        isUnlocked[0][0]=false;
        //debugging purpose dont mind it
        
        
        BombCreation();
        checkSurrounding();

        while(checkAllUnlocked()==false){
            f:
            system("cls");
            makeMap(mapSize);

            int todo;
            cout<<"\n What to do : ";
            cout<<"\n 1. Unlock a space";
            cout<<"\n 2. Flag as bomb";
            cout<<"\n 3. Unflag as coordinate";
            cout<<"\n Choice : ";
            cin>>todo;
    
            if((todo<1)||(todo>3)){   
                ClearInputBuffer();
                cout<<"Choose an integer betweenn 1-3\n";
                system("pause");
                goto f;
            }
            d:
            cout<<"\nInput x Coordinate (current column) to guess : ";
            cin>>koordinatTX;
            if((koordinatTX>=0)&&(koordinatTX<mapSize)){

                e:
                cout<<"\nInput y Coordinate (current row) to guess : ";
                cin>>koordinatTY;
                if(todo==1){
                    if(isUnlocked[koordinatTX][koordinatTY]==true){
                        cout<<"Coordinates already unlocked\n";
                        system("pause");
                    }
                    else if((koordinatTY>=0)&&(koordinatTY<mapSize)){
                        isUnlocked[koordinatTX][koordinatTY]=true;
                    }
                    else{
                        cout<<"Input should be an integer smaller than the map size\n";
                        system("pause");
                        goto e;
                    }
                }
                else if (todo==2){
                    if(isFlagged[koordinatTX][koordinatTY]==true){
                        cout<<"Spot has been flagged, choose another coordinate\n";
                    }
                    else{
                        isFlagged[koordinatTX][koordinatTY]=true;
                    }
                }

                else if (todo=3){
                    if(isFlagged[koordinatTX][koordinatTY]==false){
                        cout<<"Spot has not yet to be flagged!";
                    }
                    else{
                        isFlagged[koordinatTX][koordinatTY]=false;
                    }
                }
                

            }

            else{
                ClearInputBuffer();
                cout<<"Input should be an integer smaller than the map size\n";
                system("pause");
                goto d;
            }
        }
        cout<<"The game has ended\n";
        cout<<"You have "<<gameResult<<endl;
        cout<<"Time Spent : ";
// lnjt













            // else if (todo==2){ //flag bomb
            //     isFlagged[koordinatTX][koordinatTY]=true;
            // }   
            // else if(todo==3){ //unflag bomb
            //     isFlagged[koordinatTX][koordinatTY]=false;
            // }     
            // else{
            //     ClearInputBuffer();
            //     cout<<"Choose an integer between 1-3\n";
            //     system("pause");
            //     goto f;
            // }
        g:
        playMenu();
        }
    

    bool checkAllUnlocked(){
        int unlock = 0;
        for(int j = 0;j<mapSize;j++){
            for(int i=0;i<mapSize;i++){
                if (isUnlocked[i][j]){
                    unlock+=1;
                }
            }
        }
        if (unlock==(mapSize*mapSize)){
            return true;
        }
        else{
            return false;
        }
    }

    void playMenu(){
        
        int menu;
        system("cls");
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

                if((mapSize<=10)&&(mapSize>=3)){
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
                exit(0);
                //you know how i kept using goto label whenver im too lazy to think abt anythuing? ye tht turned into a problem apparently the goto g; make a whole new session and break didnt quite get me out of the whole while loop so after some discussion with my buddy gpt o've choosed to use exit to just terminate the whole shit

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
        
        for(int j = mapSize-1;j>=0;j--){
            cout<<"Row "<<j<<"  ";
            for(int i=0;i<mapSize;i++){

                if (isUnlocked[i][j]==true){

                    if (isBomb[i][j]==true){
                        cout<<"B     ";
                    }
                    else if (isNumber[i][j]==true){
                        cout<<bombAround[i][j]<<"     ";
                    }
                    else{
                        cout<<"U     ";
                    }
                }
                else if((isUnlocked[i][j]==false)&&(isFlagged[i][j]==true)){
                    cout<<"F     ";

                }
                else{
                    cout<<"*     ";
                }
            }            
            cout<<"\n"; 

        }
        cout<<"      ";
        for (int l=0;l<mapSize;l++){
            cout<<"col "<<l<<" ";
        }
        cout<<"\n";

    }

    int randomNumGenerator(){
       return rand()%mapSize;
    }

    void BombCreation(){
        for(int k=0;k<bombTotal;){
            int col = randomNumGenerator();
            int row = randomNumGenerator();

            if(!isBomb[col][row]){
                isBomb[col][row]=true;
                k++;
            }
        }
    }

    // i know there could've much much better way that didnt need this much loops and ifs but leave me alone, i make this whole shit without any thinking --> code first think later
    void checkSurrounding(){
        for(int i=0;i<mapSize;i++){
            for(int j=0;j<mapSize;j++){
                if(isBomb[i][j]==false){


                    // you should really trust me that i really regretted the fact that i didnt make this whole check thingies into function, the whole copy pasting is so tiring

                    // kiri selain sudut
                    if (i==0){
                        if(j==0){ //kiri bawah
                            // kanan atas
                            if(isBomb[i+1][j+1]==true){
                                bombAround[i][j]+=1;
                            }

                            // kanan
                            if(isBomb[i+1][j]==true){
                                bombAround[i][j]+=1;
                            }

                            // atas
                            if(isBomb[i][j+1]==true){
                                bombAround[i][j]+=1;
                            }
                        }
                        else if (j==mapSize-1){ // kiri atas
                            // kanan
                            if(isBomb[i+1][j]==true){
                                bombAround[i][j]+=1;
                            }

                            // atas
                            if(isBomb[i][j+1]==true){
                                bombAround[i][j]+=1;
                            }
                        
                            //kanan bawah
                            if(isBomb[i+1][j-1]==true){
                                bombAround[i][j]+=1;
                            }       
                        }
                        else{ 
                            // kanan atas
                            if(isBomb[i+1][j+1]==true){
                                bombAround[i][j]+=1;
                            }

                            // kanan
                            if(isBomb[i+1][j]==true){
                                bombAround[i][j]+=1;
                            }

                            //bawah
                            if(isBomb[i][j-1]==true){
                                bombAround[i][j]+=1;
                            }

                            // atas
                            if(isBomb[i][j+1]==true){
                                bombAround[i][j]+=1;
                            }


                            //kanan bawah
                            if(isBomb[i+1][j-1]==true){
                                bombAround[i][j]+=1;
                            }
                        }
                    }

                    // kanan selain sudut
                    else if (i==mapSize-1){
                        if(j==0){ //kanan bawah
                           // atas
                            if(isBomb[i][j+1]==true){
                                bombAround[i][j]+=1;
                            }

                            // kiri
                            if(isBomb[i-1][j]==true){
                                bombAround[i][j]+=1;
                            }
                        
                            //kiri atas
                            if(isBomb[i-1][j+1]==true){
                                bombAround[i][j]+=1;
                            }
                        }
                        
                        else if(j==mapSize-1){ // kanan atas
                            // kiri bawah
                            if(isBomb[i-1][j-1]==true){
                                bombAround[i][j]+=1;
                            }

                            // kiri
                            if(isBomb[i-1][j]==true){
                                bombAround[i][j]+=1;
                            }
                        
                            //bawah
                            if(isBomb[i][j-1]==true){
                                bombAround[i][j]+=1;
                            }                    

                        }
                        
                        else{
                            // kiri bawah
                            if(isBomb[i-1][j-1]==true){
                                bombAround[i][j]+=1;
                            }

                            // kiri
                            if(isBomb[i-1][j]==true){
                                bombAround[i][j]+=1;
                            }

                            //kiri atas
                            if(isBomb[i-1][j+1]==true){
                                bombAround[i][j]+=1;
                            }
    
                            //bawah
                            if(isBomb[i][j-1]==true){
                                bombAround[i][j]+=1;
                            }

                            // atas
                            if(isBomb[i][j+1]==true){
                                bombAround[i][j]+=1;
                            }

                        }

                    }

                    // atas selain sudut
                    else if(j==mapSize-1){
                        // kiri bawah
                        if(isBomb[i-1][j-1]==true){
                            bombAround[i][j]+=1;
                        }

                        //bawah
                        if(isBomb[i][j-1]==true){
                            bombAround[i][j]+=1;
                        }

                        //kanan bawah
                        if(isBomb[i+1][j-1]==true){
                            bombAround[i][j]+=1;
                        }

                        // kiri
                        if(isBomb[i-1][j]==true){
                            bombAround[i][j]+=1;
                        }

                        // kanan
                        if(isBomb[i+1][j]==true){
                            bombAround[i][j]+=1;
                        }
                    }
                    
                    // bawah selain sudut
                    else if(j==0){
                        // kanan atas
                        if(isBomb[i+1][j+1]==true){
                            bombAround[i][j]+=1;
                        }
                        
                        // kiri
                        if(isBomb[i-1][j]==true){
                            bombAround[i][j]+=1;
                        }

                        // kanan
                        if(isBomb[i+1][j]==true){
                            bombAround[i][j]+=1;
                        }
                        
                        // atas
                        if(isBomb[i][j+1]==true){
                            bombAround[i][j]+=1;
                        }

                        //kiri atas
                        if(isBomb[i-1][j+1]==true){
                            bombAround[i][j]+=1;
                        }
                    

                    }

                    else{
                        
                        // kanan atas
                        if(isBomb[i+1][j+1]==true){
                            bombAround[i][j]+=1;
                        }

                        // kiri bawah
                        if(isBomb[i-1][j-1]==true){
                            bombAround[i][j]+=1;
                        }

                        // kanan
                        if(isBomb[i+1][j]==true){
                            bombAround[i][j]+=1;
                        }

                        // atas
                        if(isBomb[i][j+1]==true){
                            bombAround[i][j]+=1;
                        }

                        // kiri
                        if(isBomb[i-1][j]==true){
                            bombAround[i][j]+=1;
                        }
                    
                        //bawah
                        if(isBomb[i][j-1]==true){
                            bombAround[i][j]+=1;
                        }
                    
                        //kiri atas
                        if(isBomb[i-1][j+1]==true){
                            bombAround[i][j]+=1;
                        }
                    
                        //kanan bawah
                        if(isBomb[i+1][j-1]==true){
                            bombAround[i][j]+=1;
                        }                       
                    }

                }
                if(bombAround[i][j]>0){
                    isNumber[i][j]=true;
                }
            }
        }
    }

    void BlankspaceHandler(){

    }

};


int main() {
    system("cls");
    minesweeper inigamefrfr;
    inigamefrfr.playMenu();
    return 0;
}




//nanti buat biar percobaan pertama pasti bukan bomb

// sistem flag bomb
// Buka kotak: jika kena bom → game over, tampilkan semua bom.
// Tandai / hapus tanda: untuk mencurigai bom.


// Jika kotak yang dibuka berisi angka 0, buka otomatis area kosong di sekitarnya hingga batas angka > 0 (efek flood fill). Implementasi bisa rekursif atau iteratif.

// Pemain menang jika semua bom berhasil ditandai dengan benar (tidak boleh ada tanda di kotak aman). Bukan hanya dengan membuka semua kotak aman. --> buat kek teks menangnya


// Penghitung Waktu
// Catat waktu permainan (dalam detik) sejak papan pertama kali ditampilkan hingga permainan berakhir. Tampilkan saat menang atau kalah.

// Papan ditampilkan dengan rapi, lengkap dengan informasi jumlah bom yang belum ditandai dan waktu berjalan. Koordinat baris/kolom bisa menggunakan angka 1..N.



// Gambaran Umum :

// Requirements Program :
// Kelas Permainan
// Buat satu class yang menangani seluruh state permainan: papan, bom, status buka/tandai, ukuran, dan logika permainan. Jangan gunakan struct tambahan.










// Rekursi untuk flood fill diperbolehkan dan disarankan, tapi tetap bisa dengan loop.
// Validasi input dasar (ukuran papan, jumlah bom, koordinat) wajib dilakukan.
// Note: Pengembangan program bersifat fleksibel, sesuai dengan kemampuan.a





// game ends when --> user filled everything, and we do the check, if we found wrong flag, status = lost
// check it by checker wheter current coordinate is unlocked or flagged if true than status = filled, if all is filled, do check the whole board, maybe let user decide when they wanna ends it, do it later

// 