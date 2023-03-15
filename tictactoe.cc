#include<iostream>

using namespace std;

const int TABLESIZE = 3; // ONLY AVAILABLE FOR 3 IN ROW COULD CHANGE TO MORE BUT CHECK LOGIC WONT WORK

// SETTERS
char player1(){
    
    cout << "Player 1 please choose your character: ";
    char p1;
    cin >> p1;
    cin.get();
    return p1;
}

char player2(){
    cout << "Player 2 please choose your character: ";
    char p2;
    cin >> p2;
    cin.get();
    return p2;
}

void showTable(char table[TABLESIZE][TABLESIZE]){   
    for(int i = 0 ; i < TABLESIZE ; i++){
        for(int j = 0 ; j < TABLESIZE ; j++){
            
            cout << "__" << table[i][j] << "__|";
        
        }
        cout << endl;
    }
    cout << endl; 
}

// CHECKS IF GAME HAS ENDED

bool checkIfWinner(char table[TABLESIZE][TABLESIZE],char player){

    bool winner = false;
    if(table[0][0] == player && table[0][1] == player && table[0][2] == player){
        winner = true;
    }
    else if(table[1][0] == player && table[1][1] == player && table[1][2] == player){
        winner = true;
    }
    else if(table[2][0] == player && table[2][1] == player && table[2][2] == player){
        winner = true;
    }
    else if(table[0][0] == player && table[1][0] == player && table[2][0] == player){
        winner = true;
    }
    else if(table[0][1] == player && table[1][1] == player && table[2][1] == player){
        winner = true;
    }
    else if(table[0][2] == player && table[1][2] == player && table[2][2] == player){
        winner = true;
    }
    else if(table[0][0] == player && table[1][1] == player && table[2][2] == player){
        winner = true;
    }
    else if(table[0][2] == player && table[1][1] == player && table[2][0] == player){
        winner = true;
    }
    return winner;
}

// PUTS CHARACTERS IN TABLE

void putintable(char player,char table[TABLESIZE][TABLESIZE]){
    
    int row = 0,column = 0; 
    bool ok = false;
    bool available = false;
    do{
        do{
            cout << "Enter the row you want: " << endl;
            cin >> row;
            cin.get();
            if(row < TABLESIZE && row >= 0){
                ok = true;
            }
        }while(!ok);
        
        do{
            ok = false;
            cout << "Enter the columns you want: " << endl;
            cin >> column;
            cin.get();
            if(column < TABLESIZE && column >= 0){
                ok = true;
            }
        }while(!ok);
        if(table[row][column] == ' '){
            table[row][column] = player;
            available = true;
        }
        else{
            cout << "Wrong position entered" << endl;
        }
    }while(!available);
       
}

// MAIN GAME FUNTION

void startGame(char p1, char p2,char table[TABLESIZE][TABLESIZE]){
    
    bool ended = false;
    int turn = 0;
    do{
        showTable(table);
        if(turn%2 == 0){
            
            cout << "Player 1's Turn" << endl;
            putintable(p1,table);
            if(checkIfWinner(table,p1)){
                cout << "\n PLAYER 1 WON THE GAME \n \n";
                ended = true;
            }
        }
        else{
            cout << "Player 2's Turn" << endl;
            putintable(p2,table);
            if(checkIfWinner(table,p2)){
                cout << "\n PLAYER 2 WON THE GAME \n \n";
                ended = true;
            }
        }
        turn++;
        if(turn >= (TABLESIZE*TABLESIZE) && ended == false){
            ended = true;
            cout << "\n IT IS A DRAW \n \n";
        }
    }while(!ended);
    
}

// MAIN FUNTION

int main(){

    char p1,p2;
    char table[TABLESIZE][TABLESIZE];

    for(int i = 0 ;  i < TABLESIZE ; i++){
        for(int j = 0 ; j < TABLESIZE; j++){
            table[i][j] = ' ';
        }
    }  
    p1 = player1();
    p2 = player2();

    startGame(p1,p2,table);

    return 0;
}

