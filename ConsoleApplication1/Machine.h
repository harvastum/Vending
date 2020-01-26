#pragma once
#include <vector>
#include "Coin.h"
#include "Product.h"
using std::vector;
class Machine
{
public:
	Machine();
	~Machine();


	vector<Coin> coins = 
	{	
		Coin(0.1,40),
		Coin(0.2,40),
		Coin(0.5,40),
		Coin(1,40),
		Coin(2,40),
		Coin(5,40)
	};
	vector<Product> products;
};

