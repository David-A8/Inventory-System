#pragma once
#include <string>
class item
{
private: //Private variables are defined
	std::string item_name;
	int item_quantity;
	float item_price;

public: //Public variables and functions are defined
	item();
	item(std::string i_name, int i_quantity, float i_price);
	void enter_data();
	void display_data();
	std::string get_name();
	void edit_data();
};

