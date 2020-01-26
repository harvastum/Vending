// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Machine.h"
#include <iostream>
#include <iomanip>

using namespace std;

bool isInt(string line)
{
	char* p;
	strtol(line.c_str(), &p, 10);
	return *p == 0;
}

void draw(Machine m)
{	
	auto name = m.products.begin();
	auto code = m.products.begin();
	auto price = m.products.begin();
	for (size_t j = 0; j < 6; j++)
	{
		cout << string( 88, '*') << endl;		
		for (size_t i = 0; i < 4; i++)
		{
			string n = name->name;
			cout << '|' << string (10-(n.length()+1)/2, ' ') << n << string(10-n.length()/2, ' ') << "|";
			if(next(name, 1) != m.products.end())
				name = next(name, 1);
		}
		cout << endl;
		for (size_t i = 0; i < 4; i++)
		{
			string c = to_string(code->code);
			cout << '|' << setfill(' ') << setw(10) << "Kod: " << c << string(9 - (c.length()) / 2, ' ') << "|";
			if(next(code, 1) != m.products.end())code = next(code, 1);
		}
		cout << endl;
		for (size_t i = 0; i < 4; i++)
		{
			string p = to_string(price->price);
			cout << '|' << string(10-(p.length()+1)/2, ' ') << p << string(10-p.length()/2, ' ') << "|";
			if (next(name, 1) != m.products.end())price = next(code, 1);
		}
		cout << endl;
		for (size_t i = 0; i < 4; i++)
		{
			cout << '|'  << setfill(' ') << setw(21) << "|";
		}
		cout << endl;
	
	}
	cout << string(88, '*') << endl;
}
int main()
{
	Machine machine;
	std::vector <Product> products{
	Product(4.00, "M&Ms",	1),
	Product(2.00, "Paluszki", 2),
	Product(2.50, "KitKat", 3),
	Product(3.00, "Twix", 4),
	Product(3.00, "Snickers", 5),
	Product(3.00, "Bounty", 6),
	Product(2.50, "Mentos", 7),
	Product(2.50, "Doritos", 8),
	Product(3.00, "Lays solone", 9),
	Product(3.00, "Lays zielona cebulka", 10),
	Product(2.00, "Cheetos", 11),
	Product(3.50, "Skittles", 12),
	Product(2.50, "Oreo", 13),
	Product(2.00, "Zupka Vifon", 14),
	Product(2.00, "Coca-cola", 15),
	Product(2.20, "Pepsi", 16),
	Product(1.60, "Woda niegazowana", 17),
	Product(4.50, "Monster", 18),
	Product(5.00, "Red Bull", 19),
	Product(2.20, "Black", 20),
	Product(2.20, "Black", 21),
	Product(2.20, "Black", 22),
	Product(2.20, "Black", 23),
	Product(2.20, "Black", 24),
	};
	machine.products = products;
	draw(machine);
	string line="";
	while(true)
	{
		cout << "Co chcesz kupić? (wpisz numer produktu)" << endl;
		getline(cin, line);
		if (line == "quit") break;
		int code = strtol(line.c_str(), NULL,10);
		if (code < 1 || 24 < code || !isInt(line))
		{
			cout << "Enter a code between 1 and 24." << endl;
			continue;
		}
		cout << code << endl;
	}

	system("pause");
    return 0;
}

