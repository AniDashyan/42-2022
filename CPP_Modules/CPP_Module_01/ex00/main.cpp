#include "Zombie.hpp"

int main() {
	Zombie *zombie = new Zombie("Ani");
	if (!zombie)
		return (-1);
	zombie->announce();
	Zombie *z = newZombie("Hacker");
	if (!z)
		return (-1);
	z->announce();
	randomChump("Zombik");
	delete zombie;
	delete z;
	return (0);
}