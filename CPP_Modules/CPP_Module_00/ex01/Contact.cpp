#include "Contact.hpp"
#include <iostream>

Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

Contact::Contact() {
	Contact("", "", "", "", "");
}

void Contact::displayContact() {
	
}

Contact::~Contact(void) 
{
	std::cout << "Destructor of Contact called\n";
}