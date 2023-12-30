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

void InsertionSort()
{
    default_random_engine generator(time(NULL));
    uniform_int_distribution<int> uniDist(0, 31);
    int sortArr[20];
    int temp;
    bool hasSwapped;
    for (int i = 0; i < 20; i++)
        sortArr[i] = uniDist(generator);
    PrintArr(sortArr, 20);

    for (int i = 1; i < 20; i++)
    {
        for (int j = i; j > 0; j--)
        {
            // ii is the current comparison
            if (sortArr[j] > sortArr[j - 1])
                break;
            // swap ii and i
            temp = sortArr[j];
            sortArr[j] = sortArr[j - 1];
            sortArr[j - 1] = temp;
        }
    }

    PrintArr(sortArr, 20);
}

int main()
{
    InsertionSort();
}