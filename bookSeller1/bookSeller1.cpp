// bookSeller1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "InventoryDatabase.h"
#include "CashierModule.h"

using namespace std;

void mainMenu();

int main() {
	mainMenu();
	system("pause");
	return 0;
}

void mainMenu() {
	InventoryDatabase db = InventoryDatabase("inv.dat");
	CashierModule cashier = CashierModule(db); 
	int selection;
	std::string answer; 
	do {
		cout << "Welcome to Serendipity Bookstore!" << endl;
		cout << "1. Make sale" << endl;
		cout << "2. Check inventory" << endl;
		cout << "3. Create reports" << endl;
		cout << "What would you like to do? (enter a choice between 1 and 3): ";
		cin >> selection;
		switch (selection) {
		case 1:
			cashier.cashierFunction();
			break;
		case 2:
			db.mainMenu();
			break;
		}
		std::cout << "Do you want to continue? "; 
		std::getline(std::cin, answer); 
	} while (answer != "N"); 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
