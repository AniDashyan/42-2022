#ifndef SPELL_BOOK_HPP
#define SPELL_BOOK_HPP

#include "ASpell.hpp"
#include <map>


class SpellBook {
	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell*);
		void forgetSpell(std::string const &);
		ASpell* createSpell(std::string const &);

	private:
		SpellBook(const SpellBook& other);
		SpellBook& operator=(const SpellBook& other);
		std::map<std::string, ASpell*> m_spell_book;
};
	
#endif
