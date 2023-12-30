#include <iostream>
#include <random>
#include <time.h>
#include <chrono>
#include <thread>
using namespace std;

// feel free to modify these
#define Arrlen 20 // I prefer 100
#define RandMax 20
#define Delay 100 // If you change the Arrlen, you may want to make this smaller

void PrintArr(int *arr, int size)
{
    int max = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] > max)
            max = arr[i];

    for (int i = max - 1; i >= 0; i--)
    {
        for (int j = 0; j < size; j++)
        {
            cout << (arr[j] > i ? "█" : " ");
        }
        cout << endl;
    }
}
void Clear()
{
    cout << "\x1B[2J\x1B[H"; // sketchy ANSI codes
}

void PrintArrs(int *arr, int *arr2, int size)
{
    Clear();
    cout << "Insertion Sort:" << endl;
    PrintArr(arr, size);
    cout << "Bubble Sort:" << endl;
    PrintArr(arr2, size);
    cout << "(Note that this is not an accurate speed comparison, just a representation of the algorithm)" << endl;
}

int main()
{
    // generate array
    default_random_engine generator(time(NULL));
    uniform_int_distribution<int> uniDist(1, RandMax);
    int arr[Arrlen];
    int arr2[Arrlen];
    bool hasSwapped = true;
    int temp;
    for (int i = 0; i < Arrlen; i++)
    {
        temp = uniDist(generator);
        arr[i] = temp;
        arr2[i] = temp;
    }

    // print initial state
    PrintArrs(arr, arr2, Arrlen);

    for (int i = 1; true; i++)
    {

        // insertion sort
        if (i < Arrlen)
        {
            for (int j = i; j > 0; j--)
            {
                // j is the current comparison
                if (arr[j] > arr[j - 1])
                    break;
                // swap j and i
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }

        // bubble sort
        if (hasSwapped)
        {
            hasSwapped = false;
            for (int i = 0; i < Arrlen - 1; i++)
            {
                if (arr2[i] > arr2[i + 1])
                {
                    temp = arr2[i + 1];
                    arr2[i + 1] = arr2[i];
                    arr2[i] = temp;
                    hasSwapped = true;
                }
            }
        }

        this_thread::sleep_for(chrono::milliseconds(Delay));
        PrintArrs(arr, arr2, Arrlen);

        if (!hasSwapped && i >= Arrlen)
            break;
    }
}