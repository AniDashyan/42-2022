#include "Contact.hpp"

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
	cout << "First Name: " << this.firstName << std::endl;
	cout << "Last Name: " << this.lastName << std::endl;
	cout << "Nickname: " << this.nickname << std::endl;
	cout << "Darkest Secret: " << this.darkestSecret << std::endl;
}

Contact::~Contact(void) 
{
	std::cout << "Destructor of Contact called\n";
}