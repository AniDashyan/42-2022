#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string command;
	int i = 0;

	// Instructions 
	std::cout << "-------------------- 💡 Instructions of use 💡 -------------------- \n";
	std::cout << "📜 \"ADD\": to add a new contact to PhoneBook. 📜" << std::endl;
	std::cout << "🔍 \"SEARCH\": to search for a specific contact in PhoneBook 🔍" << std::endl;
	std::cout << "🚪 \"EXIT\": to close the PhoneBook 🚪" << std::endl;
	std::cout << "❌ Any other command is wrong ❌" << std::endl;
	std::cout << "------------------------------------------------------------------ \n";

	while (42) {
		std::cout << "⌨️ Enter a command:" << std::endl;
		std::getline(std::cin, command);
		if (std::cin.eof())
				break;
		if (command.compare("ADD") == 0)
		{
			if (phoneBook.addContact(&i))
				std::cout << "✨ Contact added successfully ✨\n";
			else
			{
				std::cout << "❌ Error: Can't add contact to PhoneBook. ❌\n";
				break;
			}
			i++;
		}
		else if (command.compare("SEARCH") == 0)
			phoneBook.searchContact();
		else if (command.compare("EXIT") == 0) {
			std::cout << "🚪 Exiting PhoneBook 🚪" << std::endl;
			break;
		}
		else
			std::cout << "❌ Wrong command! Enter a valid command ❌\n";
		command.clear();
	}
	return (0);
}