#ifndef type_BOOK_HPP
#define type_BOOK_HPP

#include "ATarget.hpp"
#include <map>


class TargetGenerator {
	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget*);
		void forgetTargetType(std::string const &);
		ATarget* createTarget(std::string const &);

	private:
		TargetGenerator(const TargetGenerator& other);
		TargetGenerator& operator=(const TargetGenerator& other);
		std::map<std::string, ATarget*> m_type_book;
};
	
#endif