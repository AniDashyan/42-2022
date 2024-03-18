#include "ASpell.hpp"
#include <iostream>

ASpell::ASpell() {}
ASpell::ASpell(const std::string& name, const std::string& effects) :m_name(name), m_effects(effects) {}


ASpell::ASpell(const ASpell& other) : m_name(other.m_name), m_effects(other.m_effects) {}

ASpell& ASpell::operator=(const ASpell& other) {
	if (this != &other) {
		this->m_name = other.m_name;
		this->m_effects = other.m_effects;
	}
	return (*this);
}

ASpell::~ASpell() {}


const std::string& ASpell::getName() const {
	return (this->m_name);
}

const std::string& ASpell::getEffects() const {
	return (this->m_effects);
}

void ASpell::launch(const ATarget& target) const {
	target.getHitBySpell(*this);
}