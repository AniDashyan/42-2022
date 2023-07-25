#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact {
	private:
		std::string m_firstName;
		std::string m_lastName;
		std::string m_nickname;
		std::string m_phoneNumber;
		std::string m_darkestSecret;
	public:
		Contact();
		Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret);
		void display(void);
		~Contact(void);
};
#endif