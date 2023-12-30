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

void BubbleSort()
{
    default_random_engine generator(time(NULL));
    uniform_int_distribution<int> uniDist(0, 31);
    int sortArr[20];
    int temp;
    bool hasSwapped;
    for (int i = 0; i < 20; i++)
        sortArr[i] = uniDist(generator);
    PrintArr(sortArr, 20);

    do
    {
        // one iteration
        hasSwapped = false;
        for (int i = 0; i < 20 - 1; i++)
        {
            if (sortArr[i] > sortArr[i + 1])
            {
                temp = sortArr[i + 1];
                sortArr[i + 1] = sortArr[i];
                sortArr[i] = temp;
                hasSwapped = true;
            }
        }
    } while (hasSwapped);

    PrintArr(sortArr, 20);
}

int main()
{
    BubbleSort();
}