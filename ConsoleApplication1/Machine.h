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
	void draw();
	bool accepted_coin(Coin c);
	void return_coins();
	void add_coin(double coin);

	vector<Coin> coins  
	{	
		Coin(0.1,40),
		Coin(0.2,40),
		Coin(0.5,40),
		Coin(1,40),
		Coin(2,40),
		Coin(5,40)
	};
	vector<Coin> inserted_coins;
	vector<Product> products;
	double credit = 0;
};

