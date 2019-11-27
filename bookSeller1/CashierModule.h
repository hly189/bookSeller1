#ifndef CashierModule_h
#define CashierModule_h

#include "BookSoldInfo.h"

class CashierModule {
private: 
	//InventoryDatabase currentInventory; 
	BookSoldInfo * bookSoldArray; 
	int size; 
public: 
	// Default constructor
	CashierModule(); 

	// Constructor which take parameter 
	//CashierModule(InventoryDatabase &currentInventory);

	// Destructor
	~CashierModule(); 

	// Acessor 
	int getSoldBookArraySize();

	// Cashier Menu
	void cashierMenu(); 

	// Function to add sold Book to Array 
	void addSoldBookToArray(BookSoldInfo bookSold);

	// Function to calculate sale tax
	void calculateSaleTax(double saleTax, double retailPrice, int quantitySold);

	// Main Function for cashier
	void cashierFunction(string inputString, int quantity, double saleTax, int day, int month, int year);

};

#endif