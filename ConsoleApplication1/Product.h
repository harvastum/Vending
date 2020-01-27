#pragma once
#include <string>
using std::string;

class Product
{
public:
	Product(long double price, string name, int code);
	Product(long double price, string name, int code, int amount);
	~Product();
	Product& operator--();
	Product operator--(int);
	long double price{};
	string name;
	int code{};
	int amount = 15;
};

class AmountError : public std::exception {
public:
	const char * message() const throw()
	{
		return "Attempted to dispense an item out of stock!!!\n";
	}
};
