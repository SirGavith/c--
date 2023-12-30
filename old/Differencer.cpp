#include <iostream>
#include <list>
#include <random>
#include <time.h>
#include <iomanip>
#include <math.h>
using namespace std;

void PrintArr(int *arr, int size)
{
    cout << arr[0];
    for (int i = 1; i < size; i++)
        cout << ", " << arr[i];
    cout << endl;
}


void Differencer()
{
    int numCount;

    cout << "How many numbers do you wish to input: ";
    cin >> numCount;
    cout << "Type " << numCount << " numbers: ";

    int *ins = new int[numCount];
    for (int i = 0; i < numCount; i++) cin >> ins[i];

    PrintArr(ins, numCount);

    int minDiff = INT_MAX;
    list<pair<int, int>> pairs;

    for (int i = 0; i < numCount; i++)
    {
        for (int j = i + 1; j < numCount; j++)
        {
            int diff = fabs(ins[i] - ins[j]);
            pair pair = {ins[i], ins[j]};

            if (diff < minDiff)
            {
                pairs.clear();
                minDiff = diff;
                pairs.push_front(pair);
            }
            else if (diff == minDiff)
            {
                pairs.push_front(pair);
            }
        }
    }

    for (const auto &pair : pairs)
    {
        cout << "(" << pair.first << ", " << pair.second << ") have the smallest difference of " << minDiff << endl;
    }
}

int main()
{
    Differencer();
}