#include <iostream>
using namespace std;

//Chess game
class TicTacBoard
{
public:
    int board[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
        //-1: empty
        // 0: X
        //+1: O
    int player = 0;
    int moves = 0;

    int rows[9][3] = {{0, 1, 2},
                      {3, 4, 5},
                      {6, 7, 8},
                      {0, 3, 6},
                      {1, 4, 7},
                      {2, 5, 8},
                      {0, 4, 8},
                      {2, 4, 6}};

    bool Match(int a, int b, int c)
    {
        return board[a] != -1 && board[a] == board[b] && board[a] == board[c]; // XXX
    }

    int RowThreat(int a, int b, int c, int p)
    {
        if (board[a] == p && board[b] == p && board[c] == -1) return c; // XX_
        if (board[a] == p && board[c] == p && board[b] == -1) return b; // X_X
        if (board[b] == p && board[c] == p && board[a] == -1) return a; // _XX
        return -1;
    }

    bool Win()
    {
        for (int i = 0; i < 8; i++)
        {
            if (Match(rows[i][0], rows[i][1], rows[i][2]))
            return true;
        }
        return false;
    }


    int Threat(int priority) // prioritize one player
    {
        //rows, cols, and diags
        
        // first check for Priority
        int t;
        for (int i = 0; i < 8; i++) {
            t = RowThreat(rows[i][0], rows[i][1], rows[i][2], priority);
            if  (t != -1) return t;
        }

        // then check for Non-priority
        for (int i = 0; i < 8; i++)
        {
            t = RowThreat(rows[i][0], rows[i][1], rows[i][2], (priority + 1) % 2);
            if (t != -1) return t;
        }

        return -1;
    }

    void Move(int cell, bool p = true)
    {
        if (cell < 9 && cell >= 0 && board[cell] == -1)
        {
            board[cell] = player;
            moves++;
            if (moves < 9 && Win() == false)
            {
                player++;
                player %= 2;
                if (p) AI();
            }
        }
        else
            cout << "Invalid Move. Try again" << endl;
    }

    void AI()
    {
        int t = Threat(player);
        //if there's a win or a threat (wins prioritized), go there
        if (t != -1) Move(t, false);
        else {
            // otherwise choose a random valid move
            while (true) {
                int r = rand() % 9;
                if (board[r] == -1) {
                    Move(r, false);
                    break;
                }
            }
        }
    }

    char PrintCell(int cell)
    {
        int c = board[cell];

        if (c == -1)
            cout << (
                  cell == 0 ? "0️⃣ "
                : cell == 1 ? "1️⃣ "
                : cell == 2 ? "2️⃣ "
                : cell == 3 ? "3️⃣ "
                : cell == 4 ? "4️⃣ "
                : cell == 5 ? "5️⃣ "
                : cell == 6 ? "6️⃣ "
                : cell == 7 ? "7️⃣ "
                : cell == 8 ? "8️⃣ "
                : "??");
        else if (c == 0)
            cout << "❌";
        else if (c == 1)
            cout << "⭕";

        return '\0';
    }

    void Print()
    {
        cout << endl;
        cout << PrintCell(0) << "┃" << PrintCell(1) << "┃" << PrintCell(2) << endl;
        cout << "━━╋━━╋━━" << endl;
        cout << PrintCell(3) << "┃" << PrintCell(4) << "┃" << PrintCell(5) << endl;
        cout << "━━╋━━╋━━" << endl;
        cout << PrintCell(6) << "┃" << PrintCell(7) << "┃" << PrintCell(8) << endl;
        cout << endl;
    }
};

char Prompt(string p)
{
    char s;
    cout << p;
    cin >> s;
    return s;
}

void TicTacToe()
{
    int score[3] = {0, 0, 0};

    cout << "To claim a cell, type the number corresponding to that cell." << endl;

    top:
    TicTacBoard board;
    do
    {
        board.Print();
        board.Move(Prompt("Your move: ") - '0');

    } while (board.Win() == false && board.moves < 9);

    board.Print();
    if (board.Win()) {
        score[board.player]++;
        cout << (board.player == 0 ? "X" : "O") << " Won!" << endl;
    }
    else if (board.moves == 9)
    {
        cout << "It's a tie!" << endl;
        score[2]++;
    }
    cout << score[0] << " - " << score[1];
    if (score[2] > 0)
        cout << " - " << score[2];
    cout << endl;

    if (Prompt( "Want to play again? [y/n] ") == 'y') goto top;
}

int main()
{
    TicTacToe();
}