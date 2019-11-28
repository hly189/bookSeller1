#ifndef CashierModule_h
#define CashierModule_h
#include <ctime>
#include "BookSoldInfo.h"
#include "InventoryDatabase.h"

class CashierModule {
private: 
	InventoryDatabase &currentInventory; 
	BookSoldInfo * bookSoldArray; 
	int size; 
public: 
	// Default constructor
	CashierModule(); 

	// Constructor which take parameter 
	CashierModule(InventoryDatabase & currentInventory);

	// Destructor
	//~CashierModule(); 

	// Acessor 
	int getSoldBookArraySize();

	// Cashier Menu
	void cashierMenu(); 

	// Function to add sold Book to Array 
	void addSoldBookToTempArray(BookSoldInfo* currentArray, BookSoldInfo bookSoldObject, int size);

	// Function to calculate sale tax
	double calculateSaleTax(double saleTax, double retailPrice, int quantitySold);

	//  Function for input sale book infromation
	void customerInputSaleInfo();

	//string inputString, int quantity, double saleTax, int day, int month, int year

	// Print out sale book info 
	void printSaleBookInfo(std::string title, std::string isbn, std::string author, std::string publisher); 

	// Main Cashier Function
	void cashierFunction(); 


	// Function to print out recipe
	void showCustomeReceiptScreen(BookSoldInfo* tempArray, int size, double saleTax);

	// update current Sold Book Array 
	void updateCurrentSoldBookArray();
};

#endif