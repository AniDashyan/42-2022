#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>

class PhoneBook {
	private:
		Contact m_contacts[9];
		int m_numContacts;
	public:
		PhoneBook();
		void displayPrompt(std::string command);
		void displayPhoneBookHeader();
		void displayPhoneBook();
		void addContact(int *numContacts);
		void searchContact();
		~PhoneBook();
	private:
		bool onlyNumbers(std::string str);
		bool onlyLetters(std::string str);
};
#endif