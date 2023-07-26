#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	std::cout << "Welcome to Crappy Awesome PhoneBook" << std::endl;
}

void PhoneBook::displayPhoneBookHeader()
{
	std::cout << "Please enter one from the following commands" << std::endl;
	std::cout << "ADD, SEARCH or EXIT" << std::endl;
}

void PhoneBook::displayPrompt(std::string command) {
	displayPhoneBookHeader();
	std::getline(std::cin, command);
	while (42) {
		if (command.compare("ADD") == 0)
		{
			// addContact();
			std::cout << "Contact was added succesfully\n";
		}
		else if (command.compare("SEARCH") == 0) {
			// searchContact();
			std::cout << "Contact SEARCH";
		}
		else if (command.compare("EXIT") == 0)
		{
			std::cout << "EXIT phonebook" << std::endl;
			break;
		}
		else
		{
			std::cout << "Wrong command\n";
			displayPhoneBookHeader();
		}
	}
}

PhoneBook::~PhoneBook() {
	std::cout << "Destructor of PhoneBook\n";
}