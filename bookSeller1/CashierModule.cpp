#include "pch.h"
#include "CashierModule.h"

//Default Constructor 
CashierModule::CashierModule(InventoryDatabase & currentInventory) 
	: currentInventory(currentInventory) {
};

// Destructor - it is used to remove bookSoldArray
//CashierModule::~CashierModule() {};

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


//Function to add sold Book To Temp Array
void CashierModule::addSoldBookToTempArray(BookSoldInfo* currentTempArray, BookSoldInfo bookSoldObject, int size) {
	
	// If array is empty, then add new element 
	if (size == 1) { 
		currentTempArray[0] = bookSoldObject;
		return;
	}

	// If array is not empty, then start updating new array
	// Make new temp array
	BookSoldInfo* newTempArray = new BookSoldInfo[size];

	// Update new temp array from current array 
	for (int i = 0; i < size - 1; i++) {
		newTempArray[i] = currentTempArray[i];
	}
	// Add bookSoldObject to the last index of new temp array 
	newTempArray[size - 1] = bookSoldObject; 

	// Update new array 
	currentTempArray = newTempArray;
}

// Show customer receipt 
void CashierModule::showCustomeReceiptScreen(BookSoldInfo* tempArray, int size, double saleTax) {
	// Ask custermer which method do they want to pay 
	std::string selection; 
	std::cout << "How do you want to pay? " << std::endl; 
	std::getline(std::cin, selection); 

	//Show customer record 
	std::cout << "CUSTOMER REPORT" << std::endl;
	std::cout << "============================================================" << std::endl; 
	std::cout << left << setw(50) << "Item";
	std::cout << setw(25) << "ISBN";
	std::cout << setw(25) << "PRICE";
	std::cout << setw(25) << "QUANTITY";
	std::cout << setw(35) << "DATE SOLD" << std::endl;

	// Loop through array and show item
	// it will also update subtotal and total of all sold item
	double subTotal = 0.0; 
	double totalPrice = 0.0;

	for (int i = 0; i < size; i++) {
		Book tempBook = tempArray[i].getBookObject(); 
		std::cout << left << setw(60) << tempBook.getTitle(); 
		std::cout << setw(25) << tempBook.getIsbn(); 
		std::cout << setw(25) << tempArray[i].getQuantitySale();
		std::cout << setw(35) << tempArray[i].getDateSold() << std::endl;
		// Update subtotal
		subTotal = subTotal + (tempArray[i].getQuantitySale() * tempBook.getRetailPrice()); 

		// Update total price 
		totalPrice = totalPrice + tempArray[i].getTotalSalePrice(); 
	}

	// Let Customer know Subtotal, Tax and Total Price
	std::cout << "SUBTOTAL " << subTotal << std::endl; 
	std::cout << "TAX " << saleTax << std::endl; 
	std::cout << "TOTAL " << totalPrice << std::endl;
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
	BookSoldInfo * tempBookSoldArray = new BookSoldInfo[1]; 

	// Asking Customer
	std::string answer; 
	double saleTax; 
	std::cout << "Please enter sale tax: "; 
	std::cin >> saleTax; 
	std::cin.ignore(); 

	// Variable for keeping track of temp array size
	int tempSize = 0;
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

		// IF quantity sold is greater than quantity on Hand
		// Let user konw and ask if they want to contiue buying
		if (quantitySold > bookSold->getQuantityOnHand()) {
			std::cout << "Not enough item in the stock" << std::endl; 
		}
		else {

			// Let user know total price before tax 
			std::cout << "Amount due before Tax: " << bookSold->getRetailPrice() * quantitySold << std::endl; 

			// Asking for day, month and year  sold 
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

			// Initialize book sold info object and update temp array size
			BookSoldInfo bookSoldObject = BookSoldInfo(bookSold, saleTax, totalPrice, quantitySold, newRemaining, daySold, monthSold, yearSold);
			tempSize++;

			// Add book object to temparray 
			//addSoldBookToTempArray(tempBookSoldArray, bookSoldObject, tempSize); 
		}
		std::cout << "Do you want to make another purchase ? ";
		std::getline(std::cin, answer); 
	} while (answer != "N");


}



