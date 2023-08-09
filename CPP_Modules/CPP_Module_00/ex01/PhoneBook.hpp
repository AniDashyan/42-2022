#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class PhoneBook {
	private:
		Contact m_contacts[8];
		int m_numContacts;
	public:
		PhoneBook();
		bool addContact(int *numContacts);
		void searchContact();
		~PhoneBook();
	private:
		void displayPhoneBook();
		static bool onlyNumbers(std::string str);
		static bool onlyLetters(std::string str);
		std::string getInput(std::string prompt, bool (*check)(std::string));
};
#endif