#include <iostream>
#include <list>
#include <random>
#include <time.h>
#include <iomanip>
using namespace std;

void Histogram()
{
    default_random_engine generator(time(NULL));

    uniform_int_distribution<int> uniDist(0, 99);
    geometric_distribution<int> geoDist(0.05);
    normal_distribution<> nmlDist{50, 5};

    int freqs[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int num;
    cout << "How many numbers do you wish to generate? ";
    cin >> num;
    cout << "Which distribution do you wish to use?" << endl;
    cout << "[G]eometric | [U]niform | [N]ormal" << endl;
    char dist;
    cin >> dist;
    for (int i = 0; i < num; i++)
    {
        int rand;
        if (dist == 'G')
            rand = geoDist(generator);
        else if (dist == 'U')
            rand = uniDist(generator);
        else if (dist == 'N')
            rand = nmlDist(generator);

        freqs[rand / 10]++;
    }

    for (int i = 0; i < 10; i++)
    {
        string s = "";

        for (int ii = 0; ii < freqs[i]; ii++)
            s += "*";

        cout << setw(2) << i * 10;
        cout << ' ' << s << endl;
    }
}

int main()
{
    Histogram();
}