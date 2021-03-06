// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Machine.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <windows.h>
#include <sstream>
#include "main.h"
using namespace std;
using std::cout;
template<typename Numeric>
bool isNumber(const std::string s)
{
	Numeric n;
	return ((istringstream(s) >> n >> std::ws).eof());
}

bool isInt(string line)
{
	char* p;
	strtol(line.c_str(), &p, 10);
	return *p == 0;
}

void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}
void reset()
{	
	string line;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin, line);
	ClearScreen();
}

int main()
{
	Machine machine;
	std::vector <Product> products{
	Product(4.00, "M&Ms",	1, 0),
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
	string line="";

	for(;;reset())
	{

		machine.draw();
		cout << "Choose a product. Enter corresponding code." << endl;
		getline(cin, line);
		if (line == "quit") return 0;
		int code = strtol(line.c_str(), nullptr, 10);

		while (code < 1 || 24 < code || !isNumber<int>(line))
		{
			cout << "Enter a code between 1 and 24." << endl;
			cin.clear();
			getline(cin, line);
			if (line == "quit") return 0;
			code = strtol(line.c_str(), nullptr, 10);
		}

		Product&product = *find_if(machine.products.begin(), machine.products.end(), [&](Product p){return p.code == code; });
		
		if (!product.amount)
		{
			cout << "\n SOLD OUT\n";
			continue;
		}


		cout << "Name:\n" << product.name  << "Price: " << product.price << endl;
		cout << "Insert coins. Acceped coins: ";
				for (auto&c : machine.coins)if (c.amount < c.MAX_AMOUNT) cout << c.value << "   ";
		cout << endl;

		while (cin >> line)
		{	
			if (line == "quit") return 0;
			if (line == "cancel")
			{
				cin.clear();
				machine.return_coins();
				break;
			}
			long double coin = strtod(line.c_str(), nullptr);

			if (!isNumber<long double>(line) || !machine.accepted_coin(Coin(coin, 1)))
			{
				cout << "It is not an accepted coin. Accepted coins: ";
				for (auto&c : machine.coins) if (c.amount < c.MAX_AMOUNT) cout << c.value << "   ";
				cout  <<endl;
				continue;
			};
			machine.add_coin(coin);
			if (product.price <= machine.credit) break;
		}
		if (line == "cancel") continue;
		
		--product;
		cout << "Dispensing product:\n" << product.name << endl;
		cout << "\nReturning change:\n";
		machine.return_change(product.price);
		
		cout << "price:" << product.price << "credit:" << machine.credit << endl;

	}

	system("pause");
    return 0;
}

