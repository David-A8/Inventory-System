// Inventory-System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include "item.h"
#include <algorithm>
#include <list>
#include <numeric>
using namespace std;

void add_item(list<item>& item_list);
list<item>::iterator find_name(list<item>& item_list);

int main()
{
    list<item> items;
    int option = 1;
    while (option != 5){
        system("cls");
        cout << "\nShopping List";
        cout << "\nMain Menu\n";
        cout << "1. View List\n";
        cout << "2. Enter New Item\n";
        cout << "3. Edit an Item\n";
        cout << "4. Delete an Item\n";
        cout << "5. Exit\n";
        cout << "\nPlease choose from Menu: \n";
        cin >> option;
        if (option == 1) {
            system("cls");
            cout << "Shopping List\n";
            for_each(items.begin(), items.end(), [](item item_display) {
                item_display.display_data();
                });
            system("pause");
        }
        if (option == 2) {
            system("cls");
            add_item(items);
        }
        if (option == 4) {
            string i_name;
            system("cls");
            cout << "Shopping List\n";
            for_each(items.begin(), items.end(), [](item item_display) {
                item_display.display_data();
                });
            cout << "What item do you want to remove: ";
            cin >> i_name;
            auto item_del = remove_if(items.begin(), items.end(), [i_name](item& name) {
                return name.get_name() == i_name;
                });
            items.erase(item_del, items.end());
            cout << "Item deleted\n";
            system("pause");
        }
    }
}

void add_item(list<item>& item_list)
{
    item item;
    item.enter_data();
    item_list.push_back(item);
}

list<item>::iterator find_name(list<item>& item_list)
{
    return list<item>::iterator();
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
