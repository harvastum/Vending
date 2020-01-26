#include "stdafx.h"
#include "Coin.h"
#include <iostream>

Coin::Coin(double value, int amount) : _amount(amount), _value(value)
{
}

Coin::~Coin()
{
}

std::ostream& operator<<(std::ostream& stream, const Coin& c)
{
	stream << c._value;
	return stream;
}
