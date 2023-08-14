#include <iostream>
#include <iomanip>
#include <string>

int main() {

	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	// Display Table Header
	std::cout << "--------------------------------------------------\n";
	std::cout << "| " << std::setw(10) << "Variable" << " | "
			  << std::setw(10) << "Memory Address" << " | "
	          << std::setw(10) << "Value"
			  << std::setw(9) << " | "
	          << std::endl;
	
	// Displaying Table Values
	std::cout << "--------------------------------------------------\n";
	std::cout << "| " << std::setw(10) << std::left << "str" << " | " << &str << " | " << str << " | ";
	std::cout << "\n--------------------------------------------------\n";
	std::cout << "| " << std::setw(10) << std::left << "stringPTR" << " | " << stringPTR << " | " << *stringPTR << " | ";
	std::cout << "\n--------------------------------------------------\n";
	std::cout << "| " << std::setw(10) << std::left << "stringREF" << " | " << &stringREF << " | " << stringREF << " | ";
	std::cout << "\n--------------------------------------------------\n";
	return (0);
}