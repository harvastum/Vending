#pragma once
#include <vector>
#include "Coin.h"

class Machine
{
public:
	Machine();
	~Machine();
	vector<Coin> coins = { Coin(40) };
};

