/******************************************************************************/
/* File Name: Task_11_4                                                       */
/* Data: 28.01.2023                                                           */
/* Developer: Sergey Plotnikov                                                */
/* Description: Solution for task 3 of Block 11 of the C++ study course       */
/******************************************************************************/

#include <iostream>
#include <string>

bool checkInput(string upper, string middle, string lower) {

    for (int i = 0; i < 3; i++) {
        if (upper[i] == 'X' && middle[i] == 'X' && lower[i] == 'X') return false;
        if (upper[i] == 'O' && middle[i] == 'O' && lower[i] == 'O') return false;
    }

    for (int i = 0; i < 3; i++) {
        if (upper[0] == 'X' && middle[0] == 'X' && lower[0] == 'X') return false;
        if (upper[1] == 'X' && middle[1] == 'X' && lower[1] == 'X') return false;
        if (upper[2] == 'X' && middle[2] == 'X' && lower[2] == 'X') return false;
        if (upper[0] == 'O' && middle[0] == 'O' && lower[0] == 'O') return false;
        if (upper[1] == 'O' && middle[1] == 'O' && lower[1] == 'O') return false;
        if (upper[2] == 'O' && middle[2] == 'O' && lower[2] == 'O') return false;
    }

    if (upper[0] == 'X' && middle[1] == 'X' && lower[2] == 'X') return false;
    if (upper[2] == 'X' && middle[1] == 'X' && lower[0] == 'X') return false;
    if (upper[0] == 'O' && middle[1] == 'O' && lower[2] == 'O') return false;
    if (upper[2] == 'O' && middle[1] == 'O' && lower[0] == 'O') return false;

    return true;
}


std::string checkWin(std::string upper, std::string middle, std::string lower)
{
    char board[3][3] = {
        {upper[0], upper[1], upper[2]},
        {middle[0], middle[1], middle[2]},
        {lower[0], lower[1], lower[2]}
    };

    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            if(board[i][0] == 'X')
                return "Petya won";
            if(board[i][0] == 'O')
                return "Vasya won";
        }
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][0])
    {
        if(board[0][2] == 'X')
            return "Petya won";
        if(board[0][2] == 'O')
            return "Vasya won";
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == '.')
                return "Nobody";
        }
    }
    return "Nobody";
}

int main()
{
    std::string upper, middle, lower;
    std::cin >> upper >> middle >> lower;

    if(!checkInput(upper, middle, lower))
    {
        std::cout << "Incorrect";
        return 0;
    }
    std::cout << checkWin(upper, middle, lower);
    return 0;
}
