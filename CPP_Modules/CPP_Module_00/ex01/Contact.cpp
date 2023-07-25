#include "Contact.hpp"
#include <iostream>

Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret)
{
	m_firstName = firstName;
	m_lastName = lastName;
	m_nickname = nickname;
	m_phoneNumber = phoneNumber;
	m_darkestSecret = darkestSecret;
}

Contact::Contact() {
	Contact("", "", "", "", "");
}


Contact::~Contact(void) 
{
	std::cout << "Destructor of Contact called\n";
}