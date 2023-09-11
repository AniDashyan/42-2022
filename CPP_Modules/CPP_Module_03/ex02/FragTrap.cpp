#include "FragTrap.hpp"


FragTrap::FragTrap(): ClapTrap() {
    this->m_name = "Default";
    this->m_hit = 100;
    this->m_energy = 50;
    this->m_damage = 20;
    std::cout << "Constructor of FragTrap " << this->m_name << " is called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
    this->m_name = name;
    std::cout << "Constructor of FragTrap " << this->m_name << " is called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) {
    this->m_name = other.m_name;
    this->m_hit = other.m_hit;
    this->m_energy = other.m_energy;
    this->m_damage = other.m_damage;
    std::cout << "Copy Constructor of FragTrap " << this->m_name << " is called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this == &other)
    {
        this->m_name = other.m_name;
        this->m_hit = other.m_hit;
        this->m_energy = other.m_energy;
        this->m_damage = other.m_damage;
    }
    std::cout << "Copy Assignment Operator of FragTrap " << this->m_name  << " is called" << std::endl;
    return (*this);
}

void FragTrap::attack(const std::string& target) {
    if (this->m_hit == 0)
        std::cout << "HClaptrap" << this->m_name << " has died" << std::endl;
    else if (this->m_energy == 0)
            std::cout << "Claptrap" << this->m_name << "ran out of energy. Can't do anything" << std::endl;
    else {
        std::cout << "ClapTrap " << this->m_name << " attacks " << target << ", causing " << this->m_damage << " points of damage!" << std::endl;
        this->m_energy--;
    }
}

void FragTrap::takeDamage(unsigned int amount) {
    if (this->m_hit <= amount) {
        std::cout << "ClapTrap " << this->m_name << "has died" << std::endl;
        this->m_energy = 0;
        return;
    }
    this->m_hit -= amount;
    std::cout << "ClapTrap " << this->m_name << " was attacked, losing " << amount << " hit points" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
    if (this->m_energy == 0)
    {
        std::cout << "Energy points of Claptrap " << this->m_name << " ended. Can't do anything" << std::endl;
        return ;
    }
    if (this->m_hit <= 0)
		std::cout << "Cannot repair because: ClapTrap " << this->m_name << " is dead." << std::endl;
	else if (!this->m_energy)
		std::cout << "ClapTrap " << this->m_name << " is out of energy points!" << std::endl;
    else
    {
        this->m_hit += amount;
        this->m_energy--;
        std::cout << "ClapTrap " << this->m_name << "is repaired." << this->m_name << " gains " << amount << " hit points" << std::endl;
    }
}

void FragTrap::highFivesGuys(void) {
    std::cout << "Hey there! How about a positive high five to celebrate our awesome day?" << std::endl;
}