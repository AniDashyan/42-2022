#include "Zombie.hpp"

int main() {
	Zombie *zombies = zombieHorde(5, "Zombik");
	if (!zombies)
		return (-1);
	for (int i = 0; i < 5; i++)
		zombies[i].announce();
	delete [] zombies;
	return (0);
}