#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	m_numContacts = 0;
	std::cout << "📱 Greetings, welcome to My Awesome Phoenbook! 📱" << std::endl;
}

void PhoneBook::displayPhoneBookHeader()
{
	std::cout << "-------------------- 💡 Instructions of use 💡 -------------------- \n";
	std::cout << "📜 \"ADD\": to add a new contact to PhoneBook. 📜" << std::endl;
	std::cout << "🔍 \"SEARCH\": to search for a specific contact in PhoneBook 🔍" << std::endl;
	std::cout << "🚪 \"EXIT\": to close the PhoneBook 🚪" << std::endl;
	std::cout << "❌ Any other command is wrong ❌" << std::endl;
	std::cout << "------------------------------------------------------------------ \n";
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
		m_contacts[i].setIndex(i);
        std::cout << std::setw(10) << std::left << m_contacts[i].getIndex() << " | "
                  << std::setw(10) << std::left << (m_contacts[i].getFirstName().length() <= 10 ? m_contacts[i].getFirstName() : m_contacts[i].getFirstName().substr(0, 9) + ".") << " | "
                  << std::setw(10) << std::left << (m_contacts[i].getLastName().length() <= 10 ? m_contacts[i].getLastName() : m_contacts[i].getLastName().substr(0, 9) + ".") << " | "
                  << std::setw(10) << std::left << (m_contacts[i].getNickname().length() <= 10 ? m_contacts[i].getNickname() : m_contacts[i].getNickname().substr(0, 9) + ".") << " | "
				  << std::endl;
    }
}

/* ------- Validation checks ------- */
bool PhoneBook::onlyNumbers(std::string str) {
	for (size_t i = 0; i < str.length(); i++) 
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
	Contact 	contact;
	
	contact.setIndex(*numContacts);
	std::cout << "📖 To add a new contact, enter the following: 📖" << std::endl << std::endl;

	do {
		std::cout << "1️⃣ Please enter your First Name" << std::endl;
		getline(std::cin, value);
	} while (!onlyLetters(value) || value.empty());
	contact.setFirstName(value);

	do {
		std::cout << "2️⃣ Please enter your Last Name" << std::endl;
		getline(std::cin, value);
	} while (!onlyLetters(value) || value.empty());
	contact.setLastName(value);

	std::cout << "3️⃣ Please enter your chosen Nickname." << std::endl;
	getline(std::cin, value);
	contact.setNickname(value);
	
	do {
		std::cout  << "📞 Please enter your Phone Number 📞" << std::endl;
		getline(std::cin, value);
	} while (!onlyNumbers(value) || value.empty());
	contact.setPhoneNumber(value);

	do {
		std::cout << "🤫 Now, prepare to embrace your true self by unveiling your Darkest Secret. 🤫\n";
		getline(std::cin, value);
	} while (value.empty());
	contact.setDarkestSecret(value);
	value.clear();

	if (*numContacts > 8)
		m_contacts[*numContacts % 8] = contact;
	else
		m_contacts[*numContacts] = contact;
	m_numContacts++;
}

void PhoneBook::searchContact() {
	std::string s_index;
	int index;
	std::stringstream ss;
	
	std::cout << "🕵🏻‍♂️ To search for a Contact, do the following 🕵🏻‍♂️" << std::endl; 
	displayPhoneBook();
	
	do {
		std::cout << "🔮 Enter the index of the entry you wish to display. 🔮" << std::endl;
		getline(std::cin, s_index);
		ss << s_index;
		if (s_index.empty())
			return ;
		ss >> index;
		ss.ignore();
	} while (!onlyNumbers(s_index) || index >= 8);

	if (index < m_numContacts)
	{
		std::cout << "✨ \"Contact found,\" in Phonebook ✨" << std::endl;
		m_contacts[index].displayContact();
		return ;
	}
	else if (index > 8)
	{
		std::cout << "❌ Error: Index is out of range ❌" << std::endl;
		return ;
	}
	else
	{
		std::cout << "⚠️ \"Contact not found,\" in Phonebook ⚠️" << std::endl;
		return ;
	}
	// std::cin.ignore();
}

void PhoneBook::displayPrompt(std::string command) {
	int i = 0;
	while (42) {
		std::cout << "⌨️ Enter a command:" << std::endl;
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << "❌ Error: cin format failure ❌\n";
			break;
		}
		if (command.compare("ADD") == 0)
		{
			addContact(&i);
			std::cout << "✨ Contact added successfully ✨\n";
			i++;
		}
		else if (command.compare("SEARCH") == 0)
			searchContact();
		else if (command.compare("EXIT") == 0) {
			std::cout << "🚪 Exiting PhoneBook 🚪" << std::endl;
			break;
		}
		else
			std::cout << "❌ Wrong command! Enter a valid command ❌\n";
		command.clear();
	}
}

PhoneBook::~PhoneBook() {
	std::cout << "📞📖 Beware the Destructor of PhoneBook! 📞📖\n";
}
