#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	m_numContacts = 0;
	std::cout << "🏰📜🔮 Greetings, noble adventurer, to the Kingdom of Phoenbook! 🔮📜🏰" << std::endl;
	std::cout << "🌟 Behold, a realm of enchantment and wonder, where your contacts are preserved like ancient scrolls of wisdom! 🌟" << std::endl;
}

void PhoneBook::displayPhoneBookHeader()
{
	std::cout << "\n🏰 Prepare to traverse the pages of destiny with these magical commands: 🏰" << std::endl;
	std::cout << "📜 Whisper the sacred word \"ADD\" to inscribe a new character into the grand tapestry of your phonebook. 📜" << std::endl;
	std::cout << "🔍 Unravel the mysteries of \"SEARCH\" to conjure forth a contact you seek, like a hidden gem in the enchanted forest. 🔍" << std::endl;
	std::cout << "🚪 To bid farewell to this mystical realm, say \"EXIT\" and you shall return to the lands beyond. Fear not, for your quest shall be saved! 🚪" << std::endl;
	std::cout << "⚠️ Should an errant incantation escape your lips, fear not, for Phoenbook's benevolent spirits shall gently guide you back to the path of rightful commands. ⚠️\n" << std::endl;
	std::cout << "🧙‍♂️ Speak forth your command, and the mystical spirits of Phoenbook shall heed thy words!\n";
}

void PhoneBook::displayPhoneBook() {
	// Displaying header
	std::cout << std::setw(10) << "Index" << " | "
			  << std::setw(10) << "First Name" << " | "
	          << std::setw(10) << "Last Name" << " | "
	          << std::setw(10) << "Nickname" << " | "
	          << std::endl;

	// Dis\playing seperator
	std::cout << "----------------------------------------------------" << std::endl;
	for (int i = 0; i < m_numContacts; ++i) {
        std::cout << std::setw(10) << m_contacts[i].getIndex() << " | "
                  << std::setw(10) << std::left << (m_contacts[i].getFirstName().length() <= 10 ? m_contacts[i].getFirstName() : m_contacts[i].getFirstName().substr(0, 9) + ".") << " | "
                  << std::setw(10) << std::left << (m_contacts[i].getLastName().length() <= 10 ? m_contacts[i].getLastName() : m_contacts[i].getLastName().substr(0, 9) + ".") << " | "
                  << std::setw(10) << std::left << (m_contacts[i].getNickname().length() <= 10 ? m_contacts[i].getNickname() : m_contacts[i].getNickname().substr(0, 9) + ".") << " | "
				  << std::endl;
    }
}

bool PhoneBook::addContact(int *numContacts)
{
	std::string value;
	
	m_contacts[*numContacts].setIndex(*numContacts);
	std::cout << "📖 To inscribe your presence in the Chronicles of Phoenbook, reveal thyself with the following: 📖" << std::endl << std::endl;
	std::cout << "1️⃣ Whisper your First Name, and the very essence of your being shall be etched upon these enchanted pages!" << std::endl;
	if (*numContacts > 8)
	{
		std::cout << "🌟✨🚧 Phoenbook's Celestial Tapestry is Full! 🚧✨🌟\n";
		return (0);
	}
	getline(std::cin, value);
	m_contacts[*numContacts].setFirstName(value);
	std::cout << "2️⃣ Next, reveal your Last Name, and the melodies of your legacy shall resonate throughout the ethereal realms!" << std::endl;
	getline(std::cin, value);
	m_contacts[*numContacts].setLastName(value);
	std::cout << "3️⃣ Speak your chosen Nickname, a token of the secret charm that makes you uniquely enchanting in this mystical domain!" << std::endl;
	getline(std::cin, value);
	m_contacts[*numContacts].setNickname(value);
	std::cout  << "📞 Please share your mystical phone number, a key to open doors of communication in this enchanted realm: 📞" << std::endl;
	getline(std::cin, value);
	if (std::all_of(value.begin(), value.end(), ::isdigit))
		m_contacts[*numContacts].setPhoneNumber(value);
	else
	{
		std::cout << "⚠️Wrong input: Phone number should only conatin  numbers⚠️"<< std::endl;
		return (0);
	}
	std::cout << "🔮 Now, prepare to embrace your true self by unveiling your Darkest Secret. Fear not, for Phoenbook keeps secrets safe, and your truth shall be safeguarded by the ancient magic of its sacred pages.\n";
	getline(std::cin, value);
	m_contacts[*numContacts].setDarkestSecret(value);
	m_numContacts++;
	std::cout << "m_numContacts:  " << m_numContacts << "\n";
	std::cout << "numContacts:    " << numContacts << "\n";
	return (1);
}

bool PhoneBook::searchContact() {
	int index;

	displayPhoneBook();
	std::cout << "🔮 Enter the index of the entry you wish to display. 🔮" << std::endl;
	std::cin >> index;
	if (index < m_numContacts)
	{
		m_contacts[index].displayContact(index);
		return (1);
	}
	return (0);
}

void PhoneBook::displayPrompt(std::string command) {
	displayPhoneBookHeader();
	std::getline(std::cin, command);

	int i = 0;
	while (42) {
		if (command.compare("ADD") == 0)
		{
			if (addContact(&i))
			{
				std::cout << "🌌 Your contact has been inscribed with the touch of magic, forever preserved within these enchanted pages: 🌌\n";
				std::cout << "🌟✨📔 Celebrate the Birth of a New Contact: Your Cosmic Connection is Sealed! 📔✨🌟" << std::endl;
				i++;
			}
			else
			{
				std::cout << "🏰 Though your intentions were true, it seems the mystical realm of Phoenbook is unwavering in its decree. 🏰" << std::endl;
			}
			displayPhoneBook();
		}
		else if (command.compare("SEARCH") == 0) {	
			if (searchContact())
			{
				std::cout << "✨ \"Contact found,\" chants the chorus of benevolent spirits, guiding your steps to the long-sought gem hidden amidst the cosmic tapestry! ✨" << std::endl;
				std::cout << "🌌 Behold the wondrous connection unveiled, like a shining star in the night sky, illuminating the path of your journey. 🌌" << std::endl;
			}
			else
			{
				std::cout << "🏰 Though you have traversed the enchanted forest and ventured forth into the cosmic realm of Phoenbook, the contact you sought remains elusive! 🏰\n";
				std::cout << "⚠️ \"Contact not found,\" whispers the mystical spirits, guiding you with benevolent hearts. Fear not, for the cosmic tapestry is vast, and not all gems are easily found. ⚠️";
			}
		}
		else if (command.compare("EXIT") == 0)
		{
			std::cout << "EXIT phonebook" << std::endl;
			break;
		}
		else
		{
			std::cout << "📖 Speak the correct incantation, and Phoenbook shall gracefully respond: 📖\n";
			displayPrompt(command);
		}
	}
}

PhoneBook::~PhoneBook() {
	std::cout << "⚠️⚔️🌌 Beware the Destructor of PhoneBook! 🌌⚔️⚠️\n";
}