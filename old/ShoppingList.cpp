#include <iostream>
#include <list>
using namespace std;

void ShoppingList()
{
    list<string> list;

    auto display_list = [&]()
    {
        cout << "Current List:\n";
        int i = 0;
        for (const auto &item : list)
        {
            cout << " [" << i++ << "] " << item << "\n";
            // i++;
        }
    };

    auto add_list = [&]()
    {
        string item;
        cout << "Add to the list: ";
        cin >> item;
        list.push_front(item);
    };

    auto delete_list = [&]()
    {
        int index;

        cout << "Remove from the list (element): ";
        cin >> index;

        auto it = list.cbegin();
        for (int i = 0; i < index; i++)
            it++;
        list.erase(it);
    };

    while (true)
    {
        cout << "    Shopping List\n";
        cout << "Current list length: " << list.size() << "\n";
        cout << "[V]iew list | [A]dd to list | [D]elete from list ";

        string choice;
        cin >> choice;

        cout << "\33[2K\r";

        if (choice[0] == 'v')
            display_list();
        else if (choice[0] == 'a')
            add_list();
        else if (choice[0] == 'd')
            delete_list();
    }
}