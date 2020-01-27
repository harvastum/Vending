#include "stdafx.h"
#include "Coin.h"
#include <iostream>


class AmountError : public std::exception {
public:
	const char * message() const throw()
	{
		return "Not enough coins!!!\n";
	}
}; 

Coin::Coin(long double value, int amount) : amount(amount), value(value)
{
}

Coin::~Coin()
{
}

std::ostream& operator<<(std::ostream& stream, const Coin& c)
{
	stream << c.value;
	return stream;
}

Coin& Coin::operator--()
{
	if (this->amount == 0) throw new AmountError;
	this->amount--;
	return *this;
}

Coin Coin::operator--(int)
{
	Coin temp(*this);
	--(*this);
	return temp;
}
