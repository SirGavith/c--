#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

list<string> split(string s, string del = " ")
{
    list<string> out;

    s.append(del);

    int delSize = del.size();
    int start = 0;
    int end = s.find(del);

    while (end != -1)
    {
        out.push_back(s.substr(start, end - start));
        start = end + delSize;
        end = s.find(del, start);
    }

    return out;
}

int main()
{
    ifstream t("input.txt");
    stringstream buffer;
    buffer << t.rdbuf();

    string line;
    while (getline(buffer, line, '\n'))
    {
        auto arr = split(line, ",");
        arr.sort();

        for (auto const &i : arr)
            cout << i << ',';
        cout << "\b " << endl;
    }
}