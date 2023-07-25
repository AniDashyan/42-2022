#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>

class PhoneBook {
	private:
		Contact m_contacts[8];
		int		m_index;
	public:
		PhoneBook();
		void displayPhoneBook();
		void addContact();
		void searchContact();
		void exitContact();
		~PhoneBook();
};
#endif