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
bool boardFull(const char board[9]) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ')
            return false;
    }
    return true;
}
int main () {
    char board [9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char currentPlayer = 'X';
    int move;
    std::cout << "Witaj w grze kółko i krzyżyk!\n";
    std::cout << "Autor: Krystian Paetzke\n";
    std::cout << "Gracz 1: X\nGracz 2: O\n";
    std::cout << "Aby wykonać ruch, wpisz numer pola (1-9):\n";
    std::cout << "1 | 2 | 3\n4 | 5 | 6\n7 | 8 | 9\n";
    while (true) {
        printBoard(board);
        std::cout << "Ruch gracza " << currentPlayer << ": ";
        std::cin >> move;
        if (move < 1 || move > 9 || board[move - 1] != ' ') {
            std::cout << "Nieprawidlowy ruch. Sprobuj ponownie.\n";
            continue;
        }
        board[move - 1] = currentPlayer;
        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            std::cout << "Gracz " << currentPlayer << " wygrywa!\n";
            break;
        }
        if (boardFull(board)) {
            printBoard(board);
            std::cout << "Remis!\n";
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

