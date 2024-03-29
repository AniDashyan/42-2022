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

// getters
int Contact::getIndex(void) const {
	return this->index;
}

std::string Contact::getFirstName(void) const {
	return this->firstName;
}

std::string Contact::getLastName(void) const {
	return this->lastName;
}

std::string Contact::getNickname(void) const {
	return this->nickname;
}

std::string Contact::getPhoneNumber(void) const {
	return this->phoneNumber;
}

std::string Contact::getDarkestSecret(void) const {
	return this->darkestSecret;
}

// setters
void Contact::setFirstName(std::string _firstName) {
	firstName = _firstName;
}
void Contact::setLastName(std::string _lastName)  {
	lastName = _lastName;
}

void Contact::setNickname(std::string _nickname) {
	nickname = _nickname;
}

void Contact::setPhoneNumber(std::string _PhoneNumber) {
	phoneNumber = _PhoneNumber;
}

void Contact::setDarkestSecret(std::string _darkestSecret) {
	darkestSecret = _darkestSecret;
}

void Contact::setIndex(int _index) {
	index = _index;
}

void Contact::displayContact() {
	std::cout << "First Name: " << getFirstName() << std::endl;
	std::cout << "Last Name: " <<  getLastName()  << std::endl;
	std::cout << "Nickame: " << getNickname() << std::endl;
	std::cout << "Phone Number: " << getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << getDarkestSecret() << std::endl;
}

Contact::~Contact(void) 
{
	// std::cout << "👤 Beware the Destructor of Contact! 👤\n";
}