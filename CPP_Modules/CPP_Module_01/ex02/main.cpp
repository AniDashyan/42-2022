#include <iostream>
#include <string>

int main() {

	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	// std::cout << "Memory address of str: " << stringPTR << std::endl;
	std::cout << "---------- Memory addresses ----------\n";
	std::cout << "Memory address of str: " << &str << std::endl;
	std::cout << "Memory address of stringPTR: " << &stringPTR << std::endl;
	std::cout << "Memory address of stringREF: " << &stringREF << std::endl;
	std::cout << "--------------------------------------\n";

	std::cout << "\n---------- Values ----------\n";
	std::cout << "Values of str: " << str << std::endl;
	std::cout << "Values of stringPTR: " << *stringPTR << std::endl;
	std::cout << "Values of stringREF: " << stringREF << std::endl;
	std::cout << "--------------------------------------\n";
	return (0);
}