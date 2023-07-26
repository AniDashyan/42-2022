#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook {
	private:
		// Contact m_contacts[8];
		int		m_index;
	public:
		PhoneBook();
		void displayPrompt(std::string command);
		void displayPhoneBookHeader();
		void addContact();
		void searchContact();
		void exitPhoneBook();
		~PhoneBook();
};
#endif