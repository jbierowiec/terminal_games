#include <iostream>
using namespace std;

void displayBoard(char board[3][3])
{
    cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        cout << " ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }
        cout << "\n";
        if (i < 2)
            cout << "---+---+---\n";
    }
    cout << "\n";
}

char checkWinner(char board[3][3])
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
    }
    // Check columns
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
            return board[0][j];
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    return ' '; // no winner yet
}

bool isDraw(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main()
{
    char board[3][3];
    char turn = 'X';
    bool gameOver = false;

    // Initialize board
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }

    cout << endl;
    cout << "===== TIC TAC TOE =====\n";
    cout << endl;
    cout << "Player 1: X\nPlayer 2: O\n";
    displayBoard(board);

    while (!gameOver)
    {
        int move;
        cout << "Player " << turn << ", enter your move (1-9): ";
        cin >> move;

        if (move < 1 || move > 9)
        {
            cout << "Invalid move. Please enter a number from 1 to 9.\n";
            continue;
        }

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (board[row][col] != ' ')
        {
            cout << "That spot is already taken. Try again.\n";
        }
        else
        {
            board[row][col] = turn;
            displayBoard(board);

            char winner = checkWinner(board);
            if (winner == 'X' || winner == 'O')
            {
                cout << "Player " << winner << " wins!\n";
                gameOver = true;
            }
            else if (isDraw(board))
            {
                cout << "It's a draw!\n";
                gameOver = true;
            }
            else
            {
                if (turn == 'X')
                    turn = 'O';
                else
                    turn = 'X';
            }
        }
    }

    cout << endl;
    cout << "Game over.\n";
    cout << endl;
    return 0;
}
