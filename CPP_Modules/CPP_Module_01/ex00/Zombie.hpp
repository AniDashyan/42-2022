#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
	private:
		std::string name;
	public:
		Zombie();
		std::string getName();
		void setName(std::string name);

		void announce( void );
		Zombie *newZombie(std::string name);
		void randomChump(std::string name);
		~Zombie();
};

#endif