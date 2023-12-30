#include <iostream>
using namespace std;

class TicTacBoard
{
public:
    int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int player = 0;
    int moves = 0;

    bool Match(int a, int b, int c)
    {
        return board[a] != 0 && board[a] == board[b] && board[a] == board[c];
    }

    bool Win()
    {
        return Match(0, 1, 2) ||
               Match(3, 4, 5) ||
               Match(6, 7, 8) ||
               Match(0, 3, 6) ||
               Match(1, 4, 7) ||
               Match(2, 5, 8) ||
               Match(0, 4, 8) ||
               Match(2, 4, 6);
    }

    char PrintCell(int cell)
    {
        int c = board[cell];

        if (c == 0)
            cout << cell;
        else if (c == 1)
            cout << 'X';
        else if (c == 2)
            cout << 'O';

        return '\0';
    }

    char GetPlayerChar()
    {
        return player == 0 ? 'X' : 'O';
    }

    void Print()
    {
        cout << endl;
        cout << PrintCell(0) << "│" << PrintCell(1) << "│" << PrintCell(2) << endl;
        cout << "─┼─┼─" << endl;
        cout << PrintCell(3) << "│" << PrintCell(4) << "│" << PrintCell(5) << endl;
        cout << "─┼─┼─" << endl;
        cout << PrintCell(6) << "│" << PrintCell(7) << "│" << PrintCell(8) << endl;
        cout << endl;
    }

    void Move(int cell)
    {
        if (cell < 9 && cell >= 0 && board[cell] == 0)
        {
            board[cell] = player + 1;
            moves++;
            if (!Win())
            {
                player++;
                player %= 2;
            }
        }
        else
            cout << "Invalid Move. Try again" << endl;
    }
};

void TicTacToe()
{
    TicTacBoard board;
    do
    {
        board.Print();

        cout << board.GetPlayerChar() << "'s move: ";
        int cell;
        cin >> cell;

        board.Move(cell);

    } while (board.Win() == false && board.moves < 9);

    board.Print();
    if (board.Win())
        cout << board.GetPlayerChar() << " Won!" << endl;
    else if (board.moves == 9)
        cout << "It's a tie!" << endl;
}

int main()
{
    TicTacToe();
}