#include <iostream>
using namespace std;

class Ship
{
private:
    string name;
    int fuelLevel;
    int distanceTravelled = 0;

public:
    void reportStatus()
    {
        cout << "Ship '" << name << "' has " << fuelLevel << " fuel and has moved " << distanceTravelled << endl;
    }

    void Move(int dist)
    {
        if (dist <= fuelLevel)
        {
            // move
            distanceTravelled += dist;
            fuelLevel -= dist;
        }
    }

    void FillMeUp(int fuelAmount)
    {
        fuelLevel += fuelAmount;
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

    s1.Move(7);
    // shouldn't move

    s2.Move(3);
    // should move but be empty

    s3.FillMeUp(4);
    // should have 14 fuel

    s3.Move(12);
    // should be at 2 fuel

    s1.reportStatus();
    s2.reportStatus();
    s3.reportStatus();
}