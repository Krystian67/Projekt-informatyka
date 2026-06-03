#include <iostream>
void printBoard(const char board[9]) {
    std::cout << "\n";
    for (int i = 0; i < 9; i++) {
        std::cout << ' ' << board[i] << ' ';
        if (i % 3 != 2)
            std::cout << '|';
        if (i % 3 == 2 && i != 8)
            std::cout << "\n\n";
    }
    std::cout << "\n\n";
}
bool checkWin(const char board[9], char player){
    int lines [8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, 
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, 
        {0, 4, 8}, {2, 4, 6}             
    };
    for (int i=0; i<8; i++){
        if (board[lines[i][0]] == player && board[lines[i][1]] == player && board[lines[i][2]] == player)
            return true;
    }
    return false;
}

