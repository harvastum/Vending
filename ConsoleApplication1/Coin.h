#pragma once
#include <ostream>

class Coin
{
public:
	Coin(long double value, int amount);
	~Coin();
	Coin& operator--();
	Coin operator--(int);
	const unsigned int MAX_AMOUNT = 200;
	unsigned int amount;
	const long double value;		// as per C++ core guidelines C.131 https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c131-avoid-trivial-getters-and-setters
};

