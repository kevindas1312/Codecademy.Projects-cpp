#include <iostream>
#include <ctime>
using namespace std;

void intro(int &turn){
    cout << "Welcome to a game of Tic-Tac-Toe!\n";
    cout << "The following will be played on a 3x3 grid.\n";
    cout << "The board will consists of underscores which means that it has not been marked yet.\n";
    cout << "There will only be 6 rounds.\n";
    turn = rand()%2 + 1;
    cout << "Player 1 is user and Player 2 is NPC.\n";
    cout << "If Player 1 is unable to win, Player 2 automatically wins.\n";
    cout << "Player no. " <<turn<< " will begin the game!\n\n";
}

void character(){
        cout << "\n\nPlayer no.1 must use /\n";
        cout << "\n\nPlayer no.2 must use O\n";
}

int main(){
    string board[3][3];
    int turn=0,row1=0,col1=0,row2=0,col2=0;
    srand(time(NULL));
    intro(turn);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j] = "_";
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout << board[i][j];
        }
        cout << endl;
    }

    character();
    cout << "Let the game begin!\n\n\n" ;

    int checker = 0;
    string temp = " ";
    while(checker < 6){
        if(turn == 1){
            cout << "Row : ";
            cin >> row1;
            cout << "Column : ";
            cin >> col1;

            temp = board[row1-1][col1-1];
            
            if(temp == "/" || temp == "O"){
                cout << "Try again.\n\n";
                checker--;
                continue;
            }
            else{
                board[row1-1][col1-1] = "/";
            }
        }
        else{
            row2 = rand()%3;
            col2 = rand()%3;
            temp = board[row2][col2];
            if(temp == "/" || temp == "O"){
                checker--;
                continue;
            }
            else{
                board[row2][col2] = "O";
            }
        }

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout << board[i][j];
            }
            cout << endl << endl;
        }

        row1=0,col1=0,row2=0,col2=0;
        if(turn == 1){
            turn=2;
        }
        else{
            turn=1;
        }
        cout << "Turn no." <<turn << "\n\n";

        checker++;
    }

    // --- WIN CONDITION CHECKER ---
    bool player1Won = false;

    // 1. Check rows and columns simultaneously
    for (int i = 0; i < 3; ++i) {

        if (board[i][0] == "/" && board[i][1] == "/" && board[i][2] == "/") {
            player1Won = true;
        }

        if (board[0][i] == "/" && board[1][i] == "/" && board[2][i] == "/") {
            player1Won = true;
        }
    }

    if (board[0][0] == "/" && board[1][1] == "/" && board[2][2] == "/") {
        player1Won = true;
    }
    if (board[0][2] == "/" && board[1][1] == "/" && board[2][0] == "/") {
        player1Won = true;
    }


    if (player1Won) {
        cout << "\n\n\n=======================" << endl;
        cout << "  Player 1 has won!!!  " << endl;
        cout << "=======================" << endl;
    } else {
        cout << "\n\n\n==============================================" << endl;
        cout << "Player 1 failed to win. Player 2 (NPC) wins!" << endl;
        cout << "==============================================" << endl;
    }

    return 0;
}
