#pragma once
#ifndef Helpers_h
#define Helpers_h
#include <string>
#include <iostream>

namespace Helpers {
	// Function to split string with delimeter 
	std::string* splitString(std::string input, std::string delimiter, int* length);

	// Function to get consold line
	std::string getConsoleLine();

	// Function to validate input and correct it - int
	void correctingValidInput(int &userInput);

	// Function to validate input and correct it - double
	void correctingValidInput(double &userInput);
}
#endif