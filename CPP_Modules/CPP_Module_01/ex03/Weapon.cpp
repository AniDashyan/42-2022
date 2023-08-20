#include "Weapon.hpp"

Weapon::Weapon() {
	// std::cout << "🔫 Weapon is created 🔫" << std::endl;
}

Weapon::Weapon(std::string _type) : type(_type)
{
    std::cout << "🔫 Weapon " << this->type << " is created 🔫" << std::endl;
}

std::string Weapon::getType() {
    return this->type;
}

void Weapon::setType(std::string type) {
    this->type = type;
}

Weapon::~Weapon() {
    std::cout << "🔫❌ Weapon is destroyed 🔫❌" << std::endl;
}