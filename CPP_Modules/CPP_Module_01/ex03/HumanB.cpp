#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
	std::cout << "🙎‍♂️ HumanB " << this->_name << " is created 🙎‍♂️" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

void HumanB::attack() {
	if (!this->_weapon)
		std::cout << this->_name << " doesn't have a weapon\n";
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

HumanB::~HumanB() {
	std::cout << "❌🙎‍♂️ HumanB " << this->_name << " is destroyed ❌🙎‍♂️" << std::endl;
}