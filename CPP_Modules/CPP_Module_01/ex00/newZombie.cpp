#include "Zombie.hpp"

Zombie *newZombie(std::string name) {
	// Zombie *_newZombie = new Zombie(name);
	// if (!_newZombie)
	// 	return NULL;
	return (new Zombie(name));
}