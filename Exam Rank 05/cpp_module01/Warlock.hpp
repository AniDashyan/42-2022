#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock {
	public:
			Warlock(const std::string& name, const std::string& title);
		~Warlock();

		const std::string& getName() const;
		const std::string& getTitle() const;

		void setTitle(const std::string& title);

		void introduce() const;

		void learnSpell(ASpell* spell);
		void forgetSpell(std::string spellName);
		void launchSpell(std::string spellName, const ATarget& target);
	private:
		Warlock();
		Warlock(const Warlock& other);
		Warlock& operator=(const Warlock& other);
		std::string m_name;
		std::string m_title;
		std::map<std::string, ASpell*> m_spells;
};

#endif
