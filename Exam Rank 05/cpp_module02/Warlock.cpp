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
	this->m_spell_book.learnSpell(spell);
}

void Warlock::forgetSpell(std::string spellName) {
	this->m_spell_book.forgetSpell(spellName);
}

void Warlock::launchSpell(std::string spellName, const ATarget& target) {
	if (this->m_spell_book.createSpell(spellName))
		this->m_spell_book.createSpell(spellName)->launch(target);
}
