#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	std::cout << "Welcome to Crappy Awesome PhoneBook" << std::endl;
}

void PhoneBook::displayPhoneBookHeader()
{
	std::cout << "Please enter one from the following commands" << std::endl;
	std::cout << "ADD, SEARCH or EXIT" << std::endl;
}

void PhoneBook::addContact()
{
	cout << "Enter first name: ";cin >> m_contacts.firstName;
	cout << "Enter last name: ";cin >> m_contacts.lastName;
	cout << "Enter nickname: ";cin >> m_contacts.nickname;
	cout << "Enter darkest secret: ";cin >> m_contacts.darkestSecret;
}

void PhoneBook::displayPrompt(std::string command) {
	displayPhoneBookHeader();
	std::getline(std::cin, command);
	while (42) {
		if (command.compare("ADD") == 0)
		{
			// addContact();
			std::cout << "Contact was added succesfully\n";
			return;
		}
		else if (command.compare("SEARCH") == 0) {
			// searchContact();
			std::cout << "Contact SEARCH";
			return;
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
			return;
		}
	}
}

PhoneBook::~PhoneBook() {
	std::cout << "Destructor of PhoneBook\n";
}