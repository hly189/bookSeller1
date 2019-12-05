#include "pch.h"
#include "ReportModule.h"


ReportModule::ReportModule(InventoryDatabase& currentInventori)
	: currentInventori(currentInventori) {
}; 

//Report inventory
void ReportModule::ReportInventoryList(InventoryDatabase& currentInventory) {
	ofstream InventoryList;
	InventoryList.open("InventoryList.txt");
	std::cout << "Welcome to Report Inventory List. " << std::endl;
	InventoryList << "Welcome to Report Inventory List. " << std::endl;
	std::cout << "  Inventory list: " << std::endl;
	InventoryList << "  Inventory list: " << std::endl;

	Book* ReportBook = currentInventory.getBooksDatabase();
	int bookcount = currentInventory.getBookCount();
	for (int i = 0; i < bookcount; i++) {
		std::cout << "ISBN " << (ReportBook + i)->getIsbn() << "    | Title : " << (ReportBook + i)->getTitle() << std::endl;
		InventoryList << "ISBN " << (ReportBook + i)->getIsbn() << "  |   Title : " << (ReportBook + i)->getTitle() << std::endl;

	}

	InventoryList.close();
};

//Report WholeSale
void ReportModule::ReportWholeSaleValue(InventoryDatabase& currentInventory) {
	ofstream WholeSaleValue;
	WholeSaleValue.open("WholeSaleValue.txt");
	std::cout << "Welcome to Whole Sale Value report. " << std::endl;
	WholeSaleValue << "Welcome to Whole Sale Value report. " << std::endl;
	std::cout << " Whole Sale Value report: " << std::endl;
	WholeSaleValue << " Whole Sale Value report: " << std::endl;
	Book* ReportBook = currentInventory.getBooksDatabase();
	int bookcount = currentInventory.getBookCount();
	double TotalWholeSale = 0;

	for (int i = 0; i < bookcount; i++) {
		TotalWholeSale += (ReportBook + i)->getWholesaleCost() * (ReportBook + i)->getQuantityOnHand();
	}

	for (int counter = 0; counter < bookcount; counter++) {
		std::cout << "ISBN :" << (ReportBook + counter)->getIsbn() << " |  Title :" << (ReportBook + counter)->getTitle();
		std::cout << " |  WholeSale Cost : $" << (ReportBook + counter)->getWholesaleCost() << " |  Quantity on Hand : " << (ReportBook + counter)->getQuantityOnHand() << std::endl;
		WholeSaleValue << "ISBN :" << (ReportBook + counter)->getIsbn() << " |  Title :" << (ReportBook + counter)->getTitle() << " |  WholeSale Cost : $" << (ReportBook + counter)->getWholesaleCost() << std::endl;
	}
	std::cout << " Total Whole Sale of store : $" << TotalWholeSale << std::endl;
	WholeSaleValue << " Total Whole Sale of store : $ " << TotalWholeSale << " Dollars" << std::endl;
	WholeSaleValue.close();
}

//Report Retail Value
void ReportModule::ReportRetailValue(InventoryDatabase& currentInventory) {
	ofstream RetailValue;
	RetailValue.open("RetailValue.txt");
	std::cout << "Welcome to Retail Value report. " << std::endl;
	RetailValue << "Welcome to Retail Value report. " << std::endl;
	std::cout << " Retail Value report: " << std::endl;
	RetailValue << " Retail Value report: " << std::endl;
	Book* ReportBook = currentInventory.getBooksDatabase();
	int bookcount = currentInventory.getBookCount();
	double TotalRetailValue = 0;

	for (int i = 0; i < bookcount; i++) {
		TotalRetailValue += (ReportBook + i)->getRetailPrice() * (ReportBook + i)->getQuantityOnHand();
	}
	for (int i = 0; i < bookcount; i++) {
		std::cout << "ISBN " << (ReportBook + i)->getIsbn() << "  Title : " << (ReportBook + i)->getTitle() << "Retail Value : $" << (ReportBook + i)->getRetailPrice() << std::endl;
		RetailValue << "ISBN " << (ReportBook + i)->getIsbn() << "  Title : " << (ReportBook + i)->getTitle() << "Retail Value : $" << (ReportBook + i)->getRetailPrice() << std::endl;

	}
	std::cout << " Total Retail Value of store : $" << TotalRetailValue << std::endl;
	RetailValue << " Total Retail Value of store : $ " << TotalRetailValue << " Dollars" << std::endl;
	RetailValue.close();

}

//Main menu report
void ReportModule::ReportMainMenu(InventoryDatabase& currentInventory) {


	int menu = 0;
	do {
		std::cout << "Please Type the desired report option." << std::endl;
		std::cout << "1 for Inventory List." << std::endl;
		std::cout << "2 for Inventory Wholesale Value. " << std::endl;
		std::cout << "3 for Inventory Retail Value. " << std::endl;
		std::cout << "4 for List By Quantity." << std::endl;
		std::cout << "5 for List By cost." << std::endl;
		std::cout << "6 for list By Age." << std::endl;
		std::cout << "7 for list By Age." << std::endl;
		std::cout << "8 Exit" << std::endl;
		Helpers::correctingValidInput(menu);
		switch (menu)
		{
		case 1:
			ReportInventoryList(currentInventory);
			break;
		case 2: 
			ReportWholeSaleValue(currentInventory); 
			break; 
		case 3: 
			ReportRetailValue(currentInventory);
		default:
			break;
		}
	} while (menu != 8); 

}
