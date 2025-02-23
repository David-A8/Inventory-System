#include "item.h"
#include <iostream>
using namespace std;

item::item() : item_name(""), item_quantity(0), item_price(0.0) {}
item::item(string i_name, int i_quantity, float i_price) :item_name(i_name), item_quantity(i_quantity), item_price(i_price) {}

void item::enter_data() //Enter_data function asks the user to enter data for the item to be stored in variables
{
    cout << "\nAdd New Item";
    cout << "\nItem name: ";
    cin >> item_name;
    cout << "Item Price: ";
    cin >> item_price;
    cout << "Quantity: ";
    cin >> item_quantity;
    cout << "\nNew item added\n";
    system("pause");
    system("cls");
}

void item::display_data() // Function to display items data
{
    cout << item_name << " --- $"<< item_price << "  ("<< item_quantity <<")\n";
}

string item::get_name() // This function returns the name of the item
{
    return item_name;
}

void item::edit_data() // edit_data function allows us to enter new data in an existing item
{
    system("cls");
    cout << "Edit item\n";
    cout << "\nItem name: ";
    cin >> item_name;
    cout << "Item Price: ";
    cin >> item_price;
    cout << "Quantity: ";
    cin >> item_quantity;
    cout << "\nItem edited\n";
    system("pause");
}
