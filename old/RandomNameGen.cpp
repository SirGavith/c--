#include <iostream>
#include <list>
#include <random>
#include <time.h>
using namespace std;

void RandomNameGen() {
    default_random_engine generator(time(NULL));
    uniform_int_distribution<int> intDist(0, 5);

    string titles[6] = {"Mr.", "Sir", "Cpt.", "Dr.", "President", "Rev."};
    string names[6] = {"Simon", "Joseph", "John", "Bobby", "Matthew", "Jonathan"};
    string adjectives[6] = {"the Lionhearted", "the Great", "III", "Jr.", "VI", "PhD"};

    while (true) {
        cout << titles[rand() % 6] << " " << names[rand() % 6] << " " << adjectives[rand() % 6] << endl;
        cout << titles[intDist(generator)] << " " << names[intDist(generator)] << " " << adjectives[intDist(generator)] << endl;

        cout << "Again? [y/n]";
        char c;
        cin >> c;
        if (c == 'n') break;
    }
}