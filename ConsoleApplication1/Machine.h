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
	void add_coin(long double coin);
	void return_change(long double price);

	vector<Coin> coins;
	vector<Coin> inserted_coins{};
	vector<Product> products{};
	long double credit = 0;
};

