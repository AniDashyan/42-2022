#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	m_numContacts = 0;
	std::cout << "🏰📜🔮 Greetings, welcome to My Crappy Phoenbook! 🔮📜🏰" << std::endl;
}

void PhoneBook::displayPhoneBookHeader()
{
	std::cout << "------- 💡 Instructions of use ------- 💡\n";
	std::cout << "📜 \"ADD\": to add a new contact to PhoneBook. 📜" << std::endl;
	std::cout << "🔍 \"SEARCH\": to search for a specific contact in PhoneBook 🔍" << std::endl;
	std::cout << "🚪 \"EXIT\": to close the PhoneBook 🚪" << std::endl;
	std::cout << "⚠️ Any other command is wrong ⚠️\n" << std::endl;
}

void PhoneBook::displayPhoneBook() {
	// Displaying header
	std::cout << std::setw(10) << "Index" << " | "
			  << std::setw(10) << "First Name" << " | "
	          << std::setw(10) << "Last Name" << " | "
	          << std::setw(10) << "Nickname" << " | "
	          << std::endl;

	// Displaying seperator
	std::cout << "----------------------------------------------------" << std::endl;
	for (int i = 0; i < m_numContacts; ++i) {
        std::cout << std::setw(10) << m_contacts[i].getIndex() << " | "
                  << std::setw(10) << std::left << (m_contacts[i].getFirstName().length() <= 10 ? m_contacts[i].getFirstName() : m_contacts[i].getFirstName().substr(0, 9) + ".") << " | "
                  << std::setw(10) << std::left << (m_contacts[i].getLastName().length() <= 10 ? m_contacts[i].getLastName() : m_contacts[i].getLastName().substr(0, 9) + ".") << " | "
                  << std::setw(10) << std::left << (m_contacts[i].getNickname().length() <= 10 ? m_contacts[i].getNickname() : m_contacts[i].getNickname().substr(0, 9) + ".") << " | "
				  << std::endl;
    }
}

/* ------- Validation checks ------- */
bool PhoneBook::onlyNumbers(std::string str) {
	for (size_t i = 0; i < str.size(); i++)
		if (!std::isdigit(str[i]))
			return (false);
		return (true);
}

bool  PhoneBook::onlyLetters(std::string str) {
	for (size_t i = 0; i < str.length(); i++)
		if(!std::isalpha(str[i]))
			return (false);
	return (true);
}
/* --------------------------------- */

void PhoneBook::addContact(int *numContacts)
{
	std::string value;
	
	m_contacts[*numContacts].setIndex(*numContacts);
	std::cout << "📖 To add a new contact, enter the following: 📖" << std::endl << std::endl;
	std::cout << "1️⃣ Please enter your First Name" << std::endl;
	if (*numContacts > 8)
	{
		std::cout << "🚧 Contact limit is reached. Phonebook is Full! 🚧\n";
	}
	getline(std::cin, value);
	if (onlyLetters(value))
		m_contacts[*numContacts].setFirstName(value);
	else
	{
		std::cout << "⚠️Wrong input: First name should only conatin letters⚠️"<< std::endl;
		value.clear();
	}
	std::cout << "2️⃣ Please enter your Last Name" << std::endl;
	getline(std::cin, value);
	if (onlyLetters(value))
		m_contacts[*numContacts].setLastName(value);
	else
	{
		std::cout << "⚠️Wrong input: Last Name should only conatin letters⚠️"<< std::endl;
		value.clear();
	}
	std::cout << "3️⃣Please enter your chosen Nickname." << std::endl;
	getline(std::cin, value);
	m_contacts[*numContacts].setNickname(value);
	std::cout  << "📞 Please enter your Phone Number 📞" << std::endl;
	getline(std::cin, value);
	if (onlyNumbers(value))
		m_contacts[*numContacts].setPhoneNumber(value);
	else
	{
		std::cout << "⚠️Wrong input: Phone number should only conatin  numbers⚠️"<< std::endl;
	}
	std::cout << "🔮 Now, prepare to embrace your true self by unveiling your Darkest Secret. 🔮\n";
	getline(std::cin, value);
	m_contacts[*numContacts].setDarkestSecret(value);
	m_numContacts++;
}

void PhoneBook::searchContact() {
	int index;

	std::cout << "🕵🏻‍♂️ To search for a Contact, enter the following 🕵🏻‍♂️" << std::endl; 
	displayPhoneBook();
	std::cout << "🔮 Enter the index of the entry you wish to display. 🔮" << std::endl;
	std::cin >> index;
	if (index < m_numContacts)
	{
		std::cout << "✨ \"Contact found,\" in Phonebook ✨" << std::endl;
		m_contacts[index].displayContact(index);
	}
	else
		std::cout << "⚠️ \"Contact not found,\" in Phonebook ⚠️" << std::endl;
}

void PhoneBook::displayPrompt(std::string command) {
	int i = 0;
	while (42) {
		std::cout << "⌨️ Enter a command:" << std::endl;
		std::getline(std::cin, command);
		if (command.compare("ADD") == 0)
			addContact(&i);
		else if (command.compare("SEARCH") == 0)	
			searchContact();
		else if (command.compare("EXIT") == 0) {
			std::cout << "EXIT phonebook" << std::endl;
			break;
		}
		else
			std::cout << "⚠️ Wrong command! Enter a valid command ⚠️\n";
		command.clear();
	}
}

PhoneBook::~PhoneBook() {
	std::cout << "⚠️⚔️🌌 Beware the Destructor of PhoneBook! 🌌⚔️⚠️\n";
}