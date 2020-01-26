#pragma once
class Coin
{
public:
	Coin();
	Coin(float value, int amount);
	~Coin();
	const int MAX_AMOUNT = 200;
	unsigned int _amount;
	const float _value;		// as per C++ core guidelines

};

