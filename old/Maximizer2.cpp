#include <iostream>
#include <list>
#include <random>
#include <time.h>
#include <iomanip>
using namespace std;

void PrintArr(int *arr, int size)
{
    cout << arr[0];
    for (int i = 1; i < size; i++)
        cout << ", " << arr[i];
    cout << endl;
}

void Maximizer2()
{
    int numCount;

    cout << "How many numbers do you wish to input: ";
    cin >> numCount;
    cout << "Type " << numCount << " numbers: ";

    int *ins = new int[numCount];
    for (int i = 0; i < numCount; i++)
        cin >> ins[i];

    PrintArr(ins, numCount);

    int max = 0;

    list<pair<int, int>> pairs;

    for (int i = 0; i < numCount; i++)
    {
        for (int j = i + 1; j < numCount; j++)
        {
            int prod = ins[i] * ins[j];
            if (prod >= max)
            {
                max = prod;
                pair pair = {ins[i], ins[j]};
                pairs.push_front(pair);
            }
        }
    }

    for (const auto &pair : pairs)
    {
        cout << "Maximum product: " << pair.first << " * " << pair.second << " = " << max << endl;
    }
}

int main()
{
    Maximizer2();
}