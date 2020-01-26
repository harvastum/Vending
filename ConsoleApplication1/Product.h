#pragma once
#include <string>
using std::string;

class Product
{
public:
	Product(double price, string name, int code);
	~Product();
	int amount = 15;
	int code;
	double price;
	string name;

};

