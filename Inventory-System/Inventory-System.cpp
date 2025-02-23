// Inventory-System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> // Lines with include export libraries
#include <cstdlib>
#include <string>
#include "item.h"
#include <algorithm>
#include <list>
#include <numeric>
using namespace std; 

void add_item(list<item>& item_list); //Defines add_item function
void show_items(list<item>& item_list); //Defines show_items function
list<item>::iterator find_name(list<item>& item_list); //Defines find_name function

int main()
{
    list<item> items; //Creates a list where items will be stored
    int option = 1; 
    while (option != 5){ //Loop to show main menu options over and over until user chooses to exit
        system("cls"); //Clean the screen before displaying main menu
        cout << "\nShopping List";
        cout << "\nMain Menu\n";
        cout << "1. View List\n";
        cout << "2. Enter New Item\n";
        cout << "3. Edit an Item\n";
        cout << "4. Delete an Item\n";
        cout << "5. Exit\n";
        cout << "\nPlease choose from Menu: \n";
        cin >> option; // Catches the user's input
        if (option == 1) {
            show_items(items); //Calls the show_items function to display shopping list
            system("pause"); //Pauses the program until the user presses a key
        }
        if (option == 2) {
            system("cls");
            add_item(items); //Calls the add_item function to add a new item to the list
        }
        if (option == 3) {
            show_items(items); //Displays items before user chooses what to edit
            list<item>::iterator it; //Creates an items list iterator 
            it = find_name(items); // it varialbe calls find_name function and receives an item if it exists
            if (it != items.end()) // If the item exists, the edit_data function will be called
            {
                it->edit_data();
            }
        }
        if (option == 4) {
            string i_name;
            show_items(items);
            cout << "\nWhat item do you want to remove: ";
            cin >> i_name; //User enters the name of the item to delete
            auto item_del = remove_if(items.begin(), items.end(), [i_name](item& name) {
                return name.get_name() == i_name; // The delete built-in algorithm is used to delete an item
                });
            items.erase(item_del, items.end());
            cout << "Item deleted\n";
            system("pause");
        }
    }
}

void show_items(list<item>& item_list)
{
    system("cls");
    cout << "Shopping List\n";
    for_each(item_list.begin(), item_list.end(), [](item item_display) { 
        item_display.display_data(); //Iterates the list and called the display_data function for each item
        });
}

void add_item(list<item>& item_list)
{
    item item; // Creates a new item object
    item.enter_data(); //Calls the enter_data function to store data entered by the user
    item_list.push_back(item); // Sends the new item to the back of the list.
}

list<item>::iterator find_name(list<item>& item_list)
{
    std::string i_name;
    std::cout << "Enter the item to modify: ";
    std::cin >> i_name;
    list<item>::iterator it;
    for (it = item_list.begin(); it != item_list.end(); it++) //Iterates the list to find the item that matches the user's input
    {
        if (it->get_name() == i_name)
        {
            return it; //If the item is found, it will be returned to work with it
        }
    }
    std::cout << "Item no found. \n"; //If the item is not found, a message will be displayed
    system("pause");
    return it;
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
