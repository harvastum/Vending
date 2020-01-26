#include "stdafx.h"
#include "Machine.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;
Machine::Machine()
{

}


Machine::~Machine()
{
}

void Machine::draw()
{
	auto name = products.begin();
	auto code = products.begin();
	auto price = products.begin();
	for (size_t j = 0; j < 6; j++)
	{
		cout << string(88, '*') << endl;
		for (size_t i = 0; i < 4; i++)
		{
			string n = name->name;
			cout << '|' << string(10 - (n.length() + 1) / 2, ' ') << n << string(10 - n.length() / 2, ' ') << "|";
			if (next(name, 1) != products.end())
				name = next(name, 1);
		}
		cout << endl;
		for (size_t i = 0; i < 4; i++)
		{
			string c = to_string(code->code);
			cout << '|' << setfill(' ') << setw(12) << "Code: " << c << string(7 - (c.length()) / 2, ' ') << "|";
			if (next(code, 1) != products.end())code = next(code, 1);
		}
		cout << endl;
		for (size_t i = 0; i < 4; i++)
		{
			string p = to_string(price->price);
			cout << '|' << string(4, ' ') << "Price: " << setprecision(2) << fixed << price->price << string(5, ' ') << "|";
			if (next(name, 1) != products.end())price = next(code, 1);
		}
		cout << endl;
		for (size_t i = 0; i < 4; i++)
		{
			cout << '|' << setfill(' ') << setw(21) << "|";
		}
		cout << endl;

	}
	cout << string(88, '*') << endl;
}
bool Machine::accepted_coin(Coin c)
{
	return find_if(coins.begin(), coins.end(), [&](Coin coin) {return coin._value == c._value; }) != coins.end();
}

void Machine::return_coins()
{
	cout << "Returning coins:\n";
	for (auto coin : inserted_coins) cout << coin._value << "   ";
	cout << endl;
	inserted_coins.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	credit = 0;
}

void Machine::add_coin(double coin)
{
	inserted_coins.push_back(Coin(coin, 1));
	credit += coin;
}

//void Machine::pick()
//{
//	
//}
