#include "item.h"
#include <iostream>
using namespace std;

item::item() : item_name(""), item_quantity(0), item_price(0.0) {}
item::item(string i_name, int i_quantity, float i_price) :item_name(i_name), item_quantity(i_quantity), item_price(i_price) {}

void item::enter_data()
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

void item::display_data()
{
    cout << item_name << " --- $"<< item_price << "  ("<< item_quantity <<")\n";
}

string item::get_name()
{
    return item_name;
}

void item::edit_data()
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
