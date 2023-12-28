#include "ATarget.hpp"
#include "ASpell.hpp"
#include <iostream>

ATarget::ATarget() {}
ATarget::ATarget(const std::string& type) :m_type(type) {
}


ATarget::ATarget(const ATarget& other) : m_type(other.m_type){}

ATarget& ATarget::operator=(const ATarget& other) {
	if (this != &other) {
		this->m_type = other.m_type;
	}
	return (*this);
}

ATarget::~ATarget() {
}

void ATarget::getHitBySpell(const ASpell& spell) const {
	std::cout << this->m_type << " has been " << spell.getEffects() << "!" << std::endl;
}


const std::string& ATarget::getType() const {
	return (this->m_type);
}
