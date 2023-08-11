#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "🧟‍♂️ Constructor of Zombie 🧟" << std::endl;
}

std::string Zombie::getName() {
	return this->name;
}

void Zombie::setName(std::string name) {
	this->name = name;
}

void Zombie::announce(void) {
	std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
	std::cout << "💀🧟‍♂️ Destructor of Zombie 💀🧟‍♂️" << std::endl;
}