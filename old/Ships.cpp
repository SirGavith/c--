#include <iostream>
using namespace std;

class Ship
{
private:
    string name;
    int fuelLevel;

public:
    void reportStatus()
    {
        cout << "Ship '" << name << "' has " << fuelLevel << " fuel" << endl;
    }

    Ship(string n, int fuel = 10)
    {
        name = n;
        fuelLevel = fuel;
    }
};

int main()
{
    Ship s1("Yacht", 6);

    Ship s2("Sailboat", 3);

    Ship s3("Pontoon");

    s1.reportStatus();
    s2.reportStatus();
    s3.reportStatus();
}