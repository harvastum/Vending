#pragma once
class Coin
{
public:
	Coin(double value, int amount);
	~Coin();
	const int MAX_AMOUNT = 200;
	unsigned int _amount;
	const double _value;		// as per C++ core guidelines C.131 https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c131-avoid-trivial-getters-and-setters

};

