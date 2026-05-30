// (currently the input method use in this whole program only stops user from typing random bullshit like string in the input --> you can still input float like 1.2 without any problems but try doing it with smtg like 1.232345342, the program itself still works normally but you'll trigger the safety mechanism added to the next cin so embrace for the impact, as for why I didnt make it so user cant input float, I'm too deep into this shit, wished I noticed it much earlier. If you input smtg like 1.2332342 I assume that its not likely ur trying to play the game normally but just trying to find a bug or 2 --> dev note: sorry for the impoliteness not quite used to polite words in english)

// chekanswer(); goto g;






//i use label when im too lazy to think whether the right syntax is continue or break dont judge me its just tht much easier

// i've realized it midway but i could've just make the clearinputbuffer into a function that took string parameter(the error name) but apparently im too lazy to change it now


#define Fernandez_Lebih_Ganteng_Dari_Justin_Bieber true
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class minesweeper{
public:
    time_t startTime = time(0);
    time_t endTime = time(0);

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
    bool gameResult=true;  //true for win false for lose
    bool isFilled[10][10]; //--> would like to name it isOccupied but tbh isFilled sounds better

    
    bool AllFilled(){
        int filledAmount = 0;
        for(int j = 0; j < mapSize; j++) {
            for(int i = 0; i < mapSize; i++) {
                if((isUnlocked[i][j]==true)||(isFlagged[i][j]==true))
                    filledAmount+=1;
            }
        }
        if(filledAmount==(mapSize*mapSize)){
            return true;
        }
        else{
            return false;
        }
    }

    void unlockAllBomb(){
        for(int j = 0; j < mapSize; j++) {
            for(int i = 0; i < mapSize; i++) {
                if(isBomb[i][j] == true){
                    isUnlocked[i][j]=true;
                }
            }
        }
    }

    void checkAnswer(){
        int correctAnswer = 0;

        for(int j = 0; j < mapSize; j++) {
            for(int i = 0; i < mapSize; i++) {
                if(isFlagged[i][j]==isBomb[i][j]){
                    correctAnswer+=1;
                }
            }
        }
        if (correctAnswer<bombTotal){
            gameResult=false;
        }
    }

    void play(){
        gameResult=true;
        //map reset
        for(int j = 0; j < mapSize; j++) {
            for(int i = 0; i < mapSize; i++) {
                isBomb[i][j] = false;
                isUnlocked[i][j] = false;
                isNumber[i][j] = false;
                bombAround[i][j] = 0;
                isBlank[i][j] = true;
                isFlagged[i][j] = false;  
                isFilled[i][j]=false;
            }
        }
                
        BombCreation();
        checkSurrounding();

        while(Fernandez_Lebih_Ganteng_Dari_Justin_Bieber){
            f:

            system("cls");
            makeMap(mapSize);

            int todo;
            
            if(gameResult==true){
                cout<<"\n What to do : ";
                cout<<"\n 1. Unlock a space";
                cout<<"\n 2. Flag as bomb";
                cout<<"\n 3. Unflag as coordinate";
                if(AllFilled()==false){
                    cout<<"\n Choice : ";
                }
            }

            else if(gameResult==false){
                cout<<"You lose!\n";
                cout<<"Answer : \n";
                unlockAllBomb();
                makeMap(mapSize);
                system("pause");
                
                goto g;
            }
            // again, i know how much of a bad practice it is but tbh the amount of line this code has is enough to stop me from touching this spaghetti code

            if(AllFilled()==true){
                cout<<"\n 4. Check answer (no return after this process)";
                cout<<"\n Choice : ";
            }
            cin>>todo;
            if(AllFilled()==false){
                if((todo<1)||(todo>3)){   
                    ClearInputBuffer();
                    cout<<"Choose an integer betweenn 1-3\n";
                    system("pause");
                    goto f;
                }
            }
            else if(AllFilled()==true){
                if((todo<1)||(todo>4)){
                    ClearInputBuffer();
                    cout<<"Choose an integer betweenn 1-4\n";
                    system("pause");
                    goto f;
                }
            }
            
            if(todo==4){
                checkAnswer();
                goto g;
            }

            d:
            cout<<"Input x Coordinate (current column) to guess : ";
            cin>>koordinatTX;
            if((koordinatTX>=0)&&(koordinatTX<mapSize)){

                e:
                cout<<"Input y Coordinate (current row) to guess : ";
                cin>>koordinatTY;
                if(todo==1){
                    if(isUnlocked[koordinatTX][koordinatTY]==true){
                        cout<<"Coordinates already unlocked\n";
                        system("pause");
                    }
                    if((isUnlocked[koordinatTX][koordinatTY]==false)&&(isFlagged[koordinatTX][koordinatTY]==true)){
                        cout<<"Coordinates already flagged\n";
                        system("pause");
                    }
                    // no need to complain abt how bad of a practice this is i know it myself, should've make a bgi if's before all of this to check for isflagged, since i did all of this wihtout planning shit i think it's kinda natural when i add new feature some legacy code needs a quick fix and this's one of the easiest i can do
                    else if((koordinatTY>=0)&&(koordinatTY<mapSize)){
                        // isUnlocked[koordinatTX][koordinatTY]=true;
                        BlankspaceHandler(koordinatTX,koordinatTY);
                    }
                    else{
                        cout<<"Input should be an integer smaller than the map size\n";
                        system("pause");
                        goto e;
                    }
                    goto f;
                }
                else if (todo==2){
                    if(isFlagged[koordinatTX][koordinatTY]==true){
                        cout<<"Spot has been flagged, choose another coordinate\n";
                        system("pause");
                    }
                    else if(isUnlocked[koordinatTX][koordinatTY]){
                        cout<<"Spot has been unlocked, choose another coordinate\n";
                        system("pause");
                    }
                    else{
                        isFlagged[koordinatTX][koordinatTY]=true;
                    }
                    goto f;
                }

                else if (todo==3){
                    if(isFlagged[koordinatTX][koordinatTY]==false){
                        cout<<"Spot has not yet to be flagged!";
                    }
                    else{
                        isFlagged[koordinatTX][koordinatTY]=false;
                    }
                    goto f;
                }

            }
        
            else{
                ClearInputBuffer();
                cout<<"Input should be an integer smaller than the map size\n";
                system("pause");
                goto d;
            }
    
        
            g:
            cout<<"The game has ended\n";
            cout<<"You have ";
            if(gameResult==true){
                cout<<"won!"<<endl;
            }
            else{
                cout<<"lost!"<<endl;   
            }
        
            cout<<"Time Spent : "<<difftime(endTime,startTime)<<" seconds.\n";
            system("pause");
            playMenu();
        }
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
        if (unlock==((mapSize*mapSize)-bombTotal)){
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
        if(gameResult==true){
            system("cls");
        }
        
        for(int j = mapSize-1;j>=0;j--){
            cout<<"Row "<<j<<"  ";
            for(int i=0;i<mapSize;i++){

                if (isUnlocked[i][j]==true){

                    if (isBomb[i][j]==true){
                        cout<<"B     ";
                        gameResult=false;
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

    void checkSurrounding() {
        for (int i = 0; i < mapSize; i++) {
            for (int j = 0; j < mapSize; j++) {
                if (isBomb[i][j]) continue; // Skip if this tile itself is a bomb

                // Look at all 8 directions around coordinate (i, j)
                for (int xOffset = -1; xOffset <= 1; xOffset++) {
                    for (int yOffset = -1; yOffset <= 1; yOffset++) {
                        int ni = i + xOffset;
                        int nj = j + yOffset;

                        // Ensure neighbor is inside the valid map bounds
                        if (ni >= 0 && ni < mapSize && nj >= 0 && nj < mapSize) {
                            if (isBomb[ni][nj]==true) {
                                bombAround[i][j]++;
                            }
                        }
                    }
                }

                if (bombAround[i][j] > 0) {
                    isNumber[i][j] = true;
                }
            }
        }
    }

    void BlankspaceHandler(int x, int y) {
        // Base cases: stop if out of bounds, already unlocked, or flagged
        if (x < 0 || x >= mapSize || y < 0 || y >= mapSize) return;
        if (isUnlocked[x][y] || isFlagged[x][y]) return;

        // Reveal the current tile
        isUnlocked[x][y] = true;

        // If it's a blank tile (0 bombs around), recursively call on all 8 neighbors
        if (bombAround[x][y] == 0) {
            for (int xOffset = -1; xOffset <= 1; xOffset++) {
                for (int yOffset = -1; yOffset <= 1; yOffset++) {
                    BlankspaceHandler(x + xOffset, y + yOffset);
                }
            }
        }
    }

};


int main() {
    srand(time(0)); //this kid from ctime used to make sure the randomnumbergenerator result changes each session
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

// the first unlocked never a bomb




