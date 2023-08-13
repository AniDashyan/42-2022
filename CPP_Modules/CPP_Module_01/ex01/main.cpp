#include "Zombie.hpp"

int main() {
	Zombie *zombie = new Zombie("Zombik");
	if (!zombie)
		return (-1);
	zombie->announce();
	Zombie *z = zombieHorde(5, "Lala");
	if (!z)
		return (-1);
	delete zombie;
	delete [] z;
	return (0);
}