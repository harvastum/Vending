#include "stdafx.h"
#include "Product.h"
using std::string;

Product::Product(double price, string name, int code): code(code), price(price), name(name)
{
}


Product::~Product() = default;
