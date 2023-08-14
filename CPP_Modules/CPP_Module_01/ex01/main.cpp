#include "Zombie.hpp"

int main() {
	// int N;
	// std::string name;

	// do {
	// 	std::cout << "Please enter a number of zombies\n N=";
	// 	std::cin >> N;
	// }
	// while (N <= 1);

	// do {
	// 	std::cout << "Please enter a name for zombies\n: name=";
	// 	if (!getline(std::cin, name))
	// 	{
	// 		if (std::cin.eof())
	// 			break;
	// 	}
	// 	if (name.empty())
	// 		std::cout << "Invalid input try again\n";
	// 	else
	// 		break;
	// }
	// while (true);

	// Zombie *zombies = zombieHorde(N ,name);
	Zombie *zombies = zombieHorde(5, "Zombik");
	if (!zombies)
		return (-1);
	for (int i = 0; i < 5; i++)
		zombies[i].announce();
	delete [] zombies;
	return (0);
}