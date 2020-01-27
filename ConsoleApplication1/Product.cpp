#include "stdafx.h"
#include "Product.h"
using std::string;

Product::Product(long double price, string name, int code)
:price(price), name(name), code(code)
{}

Product::Product(long double price, string name, int code, int amount)
: price(price), name(name), code(code), amount(amount)
{}


Product::~Product() = default;

Product& Product::operator--()
{
	if (this->amount == 0) throw new AmountError;
	this->amount--;
	return *this;
}

Product Product::operator--(int)
{	
	Product temp(*this);
	--(*this);
	return temp;
}
