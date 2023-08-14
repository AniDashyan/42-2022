#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
	private:
		std::string name;
	public:
		Zombie();
		// Zombie(std::string name);
		void setName(std::string name);
		void announce(void);
		~Zombie();
};

// Zombie *newZombie(std::string name);
// void	randomChump(std::string name);
Zombie* zombieHorde( int N, std::string name );

#endif