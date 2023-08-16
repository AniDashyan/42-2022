#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
	std::cout << "🙎‍♂️ HumanA " << this->_name << " is created 🙎‍♂️" << std::endl;
}

void HumanA::attack() {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
} 

HumanA::~HumanA() {
	std::cout << "❌🙎‍♂️ HumanA " << this->_name << " is destroyed ❌🙎‍♂️" << std::endl;
}