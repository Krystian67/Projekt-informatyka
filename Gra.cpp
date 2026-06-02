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

