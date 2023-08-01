#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>

class PhoneBook {
	private:
		Contact m_contacts[8];
		int m_numContacts;
	public:
		PhoneBook();
		void displayPrompt(std::string command);
		void displayPhoneBookHeader();
		void displayPhoneBook();
		bool addContact(int *numContacts);
		bool searchContact();
		~PhoneBook();
};
#endif