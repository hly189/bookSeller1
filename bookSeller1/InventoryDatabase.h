#ifndef InventoryDatabase_h
#define InventoryDatabase_h

//#include "Helpers.h"
#include "Book.h"
#include <fstream>
#include <string>
#include <iostream>

class InventoryDatabase {
private:
	Book* books;
	string invFilePath;
	ifstream instream;
	ofstream ostream;
	size_t bookCount = 0;
	size_t maxBooks = 1024;
public:
	// Default Constructor 
	InventoryDatabase(); 

	// Constructor which take parameter
	InventoryDatabase(std::string invFile); 
	
	// Accessor
	// return array books object
	Book* getBooksDatabase(); 

	// Function
	// Find book object 
	Book* findBook(string isbn, int* index = nullptr); 

	// Function to look up book 
	void lookUpBook(); 

	// Function to delete Book 
	void deleteBook(); 

	// Function to add book 
	void addBook(); 

	// Function to edit book 
	void editBook(); 

	// Main Menu 
	void mainMenu(); 

};

// set of helper function
namespace Helpers {
	// Function to split string with delimeter 
	std::string* splitString(string input, string delimiter, int* length);

	// Function to get consold line
	std::string getConsoleLine(); 
}
#endif
