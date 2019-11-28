#include "pch.h"
#include "CashierModule.h"

//Default Constructor 
CashierModule::CashierModule(InventoryDatabase & currentInventory) 
	: currentInventory(currentInventory) {
};

// Destructor - it is used to remove bookSoldArray
CashierModule::~CashierModule() {
	delete[] bookSoldArray; 
}

// Accessor 
// Get Book Sold Array Size 
int CashierModule::getSoldBookArraySize() {
	return this->size; 
}

// Function to calculate sale tax
double CashierModule::calculateSaleTax(double saleTax, double retailPrice, int quantitySold) {
	saleTax = saleTax / 100;

	// Calculate total sale tax 
	double totalSaleTax = retailPrice * saleTax;

	// Calculate total price which customer will have to pay 
	double totalSalePrice = (totalSaleTax + retailPrice) * quantitySold;

	return totalSalePrice;
}


// Main Function 
void CashierModule::cashierMenu() {
	int selection; 
	std::cout << "Welcome to Serendipity Cashier" << std::endl; 
	std::cout << "1. Cashier" << std::endl; 
	std::cout << "2. Cashier Report" << std::endl;
	std::cout << "What would you like to do? (enter a choice between 1 and 2): ";
	std::cin >> selection;
	switch (selection)
	{
	case 1: 
		cashierFunction();
		break;
	}
}

// Validate quantity and correct quantity input
int CashierModule::correctQuantityInput(int inputQuantity, int currentQuantity) {


	return inputQuantity; 
}

// Print out sold book info 
void CashierModule::printSaleBookInfo(std::string title, std::string isbn, std::string author, std::string publiser) {
	// Print out the information
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "The book you are looking for is" << std::endl;
	std::cout << "Book " << title << std::endl;
	std::cout << "ISBN " << isbn << std::endl;
	std::cout << "Author " << author << std::endl;
	std::cout << "Publisher " << publiser << std::endl;
}

// Main Cashier Function 
void CashierModule::cashierFunction() {

	// Validate inventory if there is book in inventory or not 
	// if not it will exit
	if (currentInventory.getBookCount() == 0) {
		std::cout << "There is no book(s) in inventory" << std::endl; 
		return; 
	}

	// Start cashier Function
	// Get the current inventory
	Book * currentBookArray = currentInventory.getBooksDatabase(); 

	// Create temp Book Sold Array 
	Book * tempBookSoldArray; 

	// Asking Customer
	std::string answer; 
	double saleTax; 
	std::cout << "Please enter sale tax: "; 
	std::cin >> saleTax; 
	std::cin.ignore(); 
	do {
		// Asking ISBN number
		std::string isbn; 
		std::cout << "Enter the ISBN Number: "; 
		std::getline(std::cin, isbn);

		// Checking if the book exist, if not
		// ask restart the loop 
		Book * bookSold = currentInventory.findBook(isbn); 
		if (bookSold == nullptr) continue; 

		// Print out the information
		printSaleBookInfo(bookSold->getTitle(), bookSold->getIsbn(), bookSold->getAuthor(), bookSold->getPublisher());
		//std::cout << "Date Added " << bookSold->getDateAdded() << std::endl; 

		// confirm to continue the sale or not
		// by restart the loop
		std::string confirm; 
		std::cout << "Is it correct ? "; 
		std::getline(std::cin, confirm); 
		if (confirm == "N") continue;

		// Asking for quantity and calculating total price 
		int quantitySold; 
		std::cout << "Price " << bookSold->getRetailPrice() << std::endl; 
		std::cout << "There are " << bookSold->getQuantityOnHand() << std::endl; 
		std::cout << "How many ? "; 
		std::cin >> quantitySold; 
		std::cin.ignore(); 
		if (quantitySold > bookSold->getQuantityOnHand()) {
			std::cout << "Not enough item in the stock" << std::endl; 
		}
		else {
			int daySold, monthSold, yearSold; 
			std::cout << "Day Sold "; 
			std::cin >> daySold; 
			std::cin.ignore();
			std::cout << "Month Sold "; 
			std::cin >> monthSold; 
			std::cin.ignore();
			std::cout << "Year Sold "; 
			std::cin >> yearSold; 
			std::cin.ignore();

			// Start calculating total price and add bookSold to temp array
			double totalPrice = calculateSaleTax(saleTax, bookSold->getRetailPrice(), quantitySold);
			
			// Update inventory 
			int newRemaining = bookSold->getQuantityOnHand() - quantitySold; 
			bookSold->setQuantityOnHand(newRemaining); 

			BookSoldInfo bookSoldObject = BookSoldInfo(bookSold, saleTax, totalPrice, quantitySold, newRemaining, daySold, monthSold, yearSold); 
		}
		std::cout << "Do you want to make another purchase ? ";
		std::getline(std::cin, answer); 
	} while (answer != "N");

}



