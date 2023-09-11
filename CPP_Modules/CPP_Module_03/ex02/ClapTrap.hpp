#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
    protected:
        std::string m_name;
        int m_hit; // health of ClapTrap
        int m_energy;
        int m_damage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        void setDamage(unsigned int damage);
        unsigned int getDamage(void);
};

#endif