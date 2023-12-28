#include "Warlock.hpp"
#include <iostream>

Warlock::Warlock() {}
Warlock::Warlock(const std::string& name, const std::string& title) :m_name(name), m_title(title) {
	std::cout << this->m_name << ": This looks like another boring day." << std::endl;
}


Warlock::Warlock(const Warlock& other) : m_name(other.m_name), m_title(other.m_title) {}

Warlock& Warlock::operator=(const Warlock& other) {
	if (this != &other) {
		this->m_name = other.m_name;
		this->m_title = other.m_title;
	}
	return (*this);
}

Warlock::~Warlock() {
	std::cout << this->m_name << ": My job here is done!" << std::endl;
	for (std::map<std::string, ASpell*>::iterator it = this->m_spells.begin(); it != this->m_spells.end(); it++) {
		delete it->second;
	}
}


const std::string& Warlock::getName() const {
	return (this->m_name);
}

const std::string& Warlock::getTitle() const {
	return (this->m_title);
}

void Warlock::setTitle(const std::string& title) {
	this->m_title = title;
}

void Warlock::introduce() const {
	std::cout << this->m_name << ": I am " << this->m_name << ", " << this->m_title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell) {
	if (spell) {
		if (this->m_spells.find(spell->getName()) == this->m_spells.end())
			   this->m_spells[spell->getName()] = spell->clone();
	}
}

void Warlock::forgetSpell(std::string spellName) {
	std::map<std::string, ASpell*>::iterator it;

	it = this->m_spells.find(spellName);
	if (it != this->m_spells.end())
		this->m_spells.erase(it);
}

void Warlock::launchSpell(std::string spellName, const ATarget& target) {
	if (this->m_spells.find(spellName) != this->m_spells.end())
		this->m_spells[spellName]->launch(target);
}
