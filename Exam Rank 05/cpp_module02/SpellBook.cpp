#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::SpellBook(const SpellBook& other) : m_spell_book(other.m_spell_book) {}

SpellBook& SpellBook::operator=(const SpellBook& other) {
	if (this != &other)
		this->m_spell_book = other.m_spell_book;

	return (*this);
}

SpellBook::~SpellBook() {
	for (std::map<std::string, ASpell*>::iterator it = this->m_spell_book.begin(); it != this->m_spell_book.end(); it++)
		delete it->second;
}


void SpellBook::learnSpell(ASpell* spell) {
	if (spell)
		this->m_spell_book[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(std::string const &spellName) {
	std::map<std::string, ASpell*>::iterator it;

	it = this->m_spell_book.find(spellName);
	if (it != this->m_spell_book.end())
	{
		delete it->second;
		this->m_spell_book.erase(it);
	}
}

ASpell* SpellBook::createSpell(std::string const &spellName) {
	if (this->m_spell_book.find(spellName) != this->m_spell_book.end())
		return (this->m_spell_book[spellName]);
	return (NULL);
}