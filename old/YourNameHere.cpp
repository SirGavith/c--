#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

//file is input.txt

class Client
{
public:
    string UserId, first_name, last_name, address, city, county, state, zip, phone1;

    void Log()
    {
        cout
            << UserId << ": "
            << first_name << " "
            << last_name << ", "
            << address << "  "
            << city << " ("
            << county << " Co.), "
            << state << " "
            << zip << " | " << phone1 << endl;
    }

    string ToString()
    {
        return UserId + "," + first_name + "," + last_name + "," + address + "," + city + "," + county + "," + state + "," + zip + "," + phone1;
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
        if (line.rfind("UserID", 0) == 0)
            continue;

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

    while (true)
    {

        char choice;
        cout << "Add a [n]ew client or [s]how all the clients ";
        cin >> choice;
        if (choice == 'n')
        {
            string UserId, first_name, last_name, address, city, county, state, zip, phone1;
            Client c;

            UserId = to_string(clients.size() + 1);
            cout << "Input the client's first_name: ";
            cin >> first_name;
            cout << "Input the client's last_name: ";
            cin >> last_name;
            cout << "Input the client's address: ";
            cin >> address;
            cout << "Input the client's city: ";
            cin >> city;
            cout << "Input the client's county: ";
            cin >> county;
            cout << "Input the client's state: ";
            cin >> state;
            cout << "Input the client's zip: ";
            cin >> zip;
            cout << "Input the client's phone1: ";
            cin >> phone1;

            c.UserId = UserId;
            c.first_name = first_name;
            c.last_name = last_name;
            c.address = address;
            c.city = city;
            c.county = county;
            c.state = state;
            c.zip = zip;
            c.phone1 = phone1;

            c.Log();

            clients.push_back(c);

            ofstream myfile;
            myfile.open("input.txt");

            string out = "UserID,first_name,last_name,address,city,county,state,zip,phone1";
            for (auto &cl : clients)
            {
                out += '\n' + cl.ToString();
            }
            myfile << out;
            myfile.close();
        }
        else if (choice == 's')
        {
            for (auto &c : clients)
            {
                c.Log();
            }
        }
    }
}