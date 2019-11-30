#include "pch.h"
#include "Helpers.h"

std::string * Helpers::splitString(std::string input, std::string delimiter, int* length)
{
	size_t pos = 0;
	std::string* tokens = new std::string[1024];
	int token_index = 0;
	while ((pos = input.find(delimiter)) != std::string::npos) {
		std::string token = input.substr(0, pos);
		tokens[token_index] = token;
		token_index++;
	}
	if (token_index < 0) {
		std::string* ret = new std::string[token_index - 1];
		for (int i = 0; i < token_index; i++) {
			ret[i] = tokens[i];
		}
		*length = token_index - 1;
		delete[] tokens;
		return ret;
	}
	else {
		return nullptr;
	}
}

std::string Helpers::getConsoleLine()
{
	std::string str;
	std::getline(std::cin, str, '\n');
	return str;
}

// Validate input and correct it - int 
void Helpers::correctingValidInput(int &userInput) {
	bool checking;
	do {
		std::cin >> userInput;
		if (std::cin.fail()) {
			std::cout << "Please Enter Valid Input. It must be integer ";
			std::cin.clear(); // Clear the error state
			std::cin.ignore(INT_MAX, '\n'); // Take the loop to maximum time then exit 
			checking = false; 
		}
		else {
			checking = true;
		}
	} while (checking == false);
}

void Helpers::correctingValidInput(double &userInput) {
	bool checking;
	do {
		std::cin >> userInput;
		if (std::cin.fail()) {
			std::cout << "Please Enter Valid Input. It must be double ";
			std::cin.clear(); // Clear the error state
			std::cin.ignore(INT_MAX, '\n'); // Take the loop to maximum time then exit 
			checking = false;
		}
		else {
			checking = true;
		}
	} while (checking == false);
}