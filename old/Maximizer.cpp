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

void InsertionSort(int *arr, int size)
{
    int temp;
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0; j--)
        {
            // ii is the current comparison
            if (arr[j] > arr[j - 1])
                break;
            // swap ii and i
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
        }
    }
}

void Maximizer()
{
    cout << "Type 10 numbers: ";
    int ins[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> ins[i];
    }

    PrintArr(ins, 10);
    int max = 0;
    for (int i = 0; i < 10; i++)
    {
        if (ins[i] > max)
            max = ins[i];
    }

    InsertionSort(ins, 10);

    cout << ins[0] * 10;

    for (int i = 1; i < 10; i++)
    {
        cout << ", " << ins[i] * max;
    }
}

int main()
{
    Maximizer();
}