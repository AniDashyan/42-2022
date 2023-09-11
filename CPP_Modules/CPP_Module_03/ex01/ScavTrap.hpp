#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class ScavTrap : public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& other);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void guardGate();
};

#endif