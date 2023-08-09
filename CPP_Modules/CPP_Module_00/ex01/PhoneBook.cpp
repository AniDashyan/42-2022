#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	m_numContacts = 0;
	std::cout <<  "📱 Greetings, welcome to My Awesome Phoenbook! 📱" << std::endl;
}

void PhoneBook::displayPhoneBook() {
	// Displaying header
	std::cout << std::setw(10) << "Index" << " | "
			  << std::setw(10) << "First Name" << " | "
	          << std::setw(10) << "Last Name" << " | "
	          << std::setw(10) << "Nickname" << " | "
	          << std::endl;

	// Displaying data
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

std::string PhoneBook::getInput(std::string prompt, bool (*check)(std::string) = 0) {
	std::string value;

	do {
        std::cout << prompt << std::endl;
		if (!getline(std::cin, value))
		{
			if (std::cin.eof())
				break;
		}
		if (value.empty())
            std::cout << "Error: Invalid input. Please try again." << std::endl; 
		else if (check && !check(value))
            std::cout << "Error: Invalid format. Please try again." << std::endl;
		else 
            break;
    }
	while (true);
	return (value);
}

bool PhoneBook::addContact(int *numContacts) {
    Contact contact;

    contact.setIndex(*numContacts);
    contact.setFirstName(getInput("1️⃣ Please enter your First Name", onlyLetters));
	if (contact.getFirstName().empty())
		return (0);
    contact.setLastName(getInput("2️⃣ Please enter your Last Name", onlyLetters));
	if (contact.getLastName().empty())
		return (0);
    contact.setNickname(getInput("3️⃣ Please enter your chosen Nickname."));
	if (contact.getNickname().empty())
		return (0);
    contact.setPhoneNumber(getInput("📞 Please enter your Phone Number 📞", onlyNumbers));
	if (contact.getPhoneNumber().empty())
		return (0);
    contact.setDarkestSecret(getInput("🤫 Now, prepare to embrace your true self by unveiling your Darkest Secret. 🤫"));
	if (contact.getDarkestSecret().empty())
		return (0);

    if (*numContacts > 8)
        m_contacts[*numContacts % 8] = contact;
    else
        m_contacts[*numContacts] = contact;
	m_numContacts++;
	return (1);
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
	} while (!onlyNumbers(s_index));

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
}

PhoneBook::~PhoneBook() {
	std::cout << "📞📖 Beware the Destructor of PhoneBook! 📞📖\n";
}
