#ifndef ATARGET_HPP
#define ATARGET_HPP

#include "ASpell.hpp"
#include <string>
class ASpell;

class ATarget {
	public:
		ATarget(const std::string& type);
		virtual ~ATarget();

		const std::string& getType() const;
	
		virtual ATarget* clone() const = 0;

		void getHitBySpell(const ASpell& spell) const;

	protected:
		ATarget();
		ATarget(const ATarget& other);
		ATarget& operator=(const ATarget& other);
		std::string m_type;
};

#endif
