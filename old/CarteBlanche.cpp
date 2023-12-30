#include <iostream>
#include <list>
#include <random>
#include <time.h>
#include <iomanip>
#include <sstream>
#include <string>
#include <math.h>
using namespace std;

void PrintArr(int *arr, int size)
{
    cout << arr[0];
    for (int i = 1; i < size; i++)
        cout << ", " << arr[i];
    cout << endl;
}

void CarteBlanche()
{
    int length;
    string walk;

    cout << "Maximum walk length: ";
    cin >> length;
    cout << "Type walk directions in one string: ";
    cin.ignore();
    getline(cin, walk);

    int walkLen = 0;
    int dY = 0;
    int dX = 0;

    for (int i = 0; i < walk.length(); i++)
    {
        switch (walk[i])
        {
        case 'n':
            dY++;
            walkLen++;
            break;
        case 's':
            dY--;
            walkLen++;
            break;
        case 'w':
            dX++;
            walkLen++;
            break;
        case 'e':
            dX--;
            walkLen++;
            break;
        }
    }
    cout << dY << " " << dX << " " << walkLen << endl;

    if (dY == 0 && dX == 0 && length == walkLen)
        cout << "true";
    else
        cout << "false";
}

int main()
{
    CarteBlanche();
}