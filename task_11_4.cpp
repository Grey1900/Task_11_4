/******************************************************************************/
/* File Name: Task_11_4                                                       */
/* Data: 28.01.2023                                                           */
/* Developer: Sergey Plotnikov                                                */
/* Description: Solution for task 3 of Block 11 of the C++ study course       */
/******************************************************************************/

#include <iostream>
#include <string>

const int N = 3;
char board[N][N];
bool win = false;
int x_count = 0, o_count = 0;

bool checkInput(char board[N][N]) {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 'X') x_count++;
            else if (board[i][j] == 'O') o_count++;
            else if (board[i][j] != '.') return false;
        }
    }
    if (x_count - o_count < 0 || x_count - o_count > 1) return false;
    return true;
}

bool checkRows(char board[N][N]) {
    for (int i = 0; i < N; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '.') return true;
    }
    return false;
}

bool checkColumns(char board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '.') return true;
        }
    }
    return false;
}

bool checkDiagonals(char board[N][N]) {
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '.') return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '.') return true;
    return false;
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> board[i][j];
        }
    }
    if (!checkInput(board)) {
        std::cout << "Incorrect" << std::endl;
        return 0;
    }
    if (checkRows(board) || checkColumns(board) || checkDiagonals(board)) {
        win = true;
    }
    if (win) {
        if (x_count > o_count) std::cout << "Petya won" << std::endl;
        else std::cout << "Vasya won" << std::endl;
    } else {
        std::cout << "Nobody" << std::endl;
    }
    return 0;
}

