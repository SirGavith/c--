#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Client {
public:
    string UserId, first_name, last_name, address, city, county, state, zip, phone1;

    void Log() {
        cout << UserId << "," << first_name << "," << last_name << "," << address << "," << city << "," << county << "," << state << "," << zip << "," << phone1 << endl;
    }
};

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
    list<Client> clients;

    string line;
    while (getline(buffer, line, '\n'))
    {
        if (line.rfind("//", 0) == 0) continue;

        list<string> l = split(line, ",");
        auto it = l.begin();
        Client c;

        c.UserId = *it;
        c.first_name = *++it;
        c.last_name = *++it;
        c.address = *++it;
        c.city = *++it;
        c.county = *++it;
        c.state = *++it;
        c.zip = *++it;
        c.phone1 = *++it;

        clients.push_back(c);
    }

    cout << "Search by [u]serId or [n]ame?";
    char search;
    cin >> search;
    cin.ignore();
    string searchTerm;

    if (search == 'n' || search == 'u') {
        cout << (search == 'n' ? "Enter the name: " : "Enter the UserID: ");
        getline(cin, searchTerm);
        bool found = false;
        for (auto &c : clients) {
            if ((search == 'n' ? (c.first_name + " " + c.last_name) : c.UserId) == searchTerm) {
                c.Log();
                found = true;
                break;
            }
        }
        if (!found) cout << "Could not find that client" << endl;
    }
}