#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>
#include <iostream>
#include <iomanip>

class Contact {
	private:
		int			index;
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		// Constructors default and initialized list
		Contact();
		Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret);

		// getters
		int getIndex(void) const;
		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickname(void) const;
		std::string getPhoneNumber(void) const;
		std::string getDarkestSecret(void) const;

		// setters
		void setIndex(int _index);
		void setFirstName(std::string _firstName);
		void setLastName(std::string _lastName);
		void setNickname(std::string _nickname);
		void setPhoneNumber(std::string _PhoneNumber);
		void setDarkestSecret(std::string _darkestSecret);

		// show 
		void displayContact(int index);
		// Destructor
		~Contact(void);
};
#endif