#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string command;
	phoneBook.displayPrompt(command);
	return (0);
}