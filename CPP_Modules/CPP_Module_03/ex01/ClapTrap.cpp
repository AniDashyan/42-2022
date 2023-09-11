#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : m_name("Default"), m_hit(100), m_energy(50), m_damage(20) {
    std::cout << "Default Constructor of ClapTrap Default is called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : m_name(name), m_hit(10), m_energy(10), m_damage(0) {
    std::cout << "Constructor with parameter of ClapTrap " << this->m_name << " is called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : m_name(other.m_name), m_hit(other.m_hit), m_energy(other.m_energy), m_damage(other.m_damage) {
    std::cout << "Copy Constructor of " << this->m_name << " is called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other)
    {
        this->m_name = other.m_name;
        this->m_hit = other.m_hit;
        this->m_energy = other.m_energy;
        this->m_damage = other.m_damage;
    }
    std::cout << "Copy Assignment Operator of" << this->m_name << " is called" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor of " << this->m_name << " is called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (this->m_hit == 0)
        std::cout << "HClaptrap" << this->m_name << " has died" << std::endl;
    else if (this->m_energy == 0)
            std::cout << "Claptrap" << this->m_name << "ran out of energy. Can't do anything" << std::endl;
    else {
        std::cout << "ClapTrap " << this->m_name << " attacks " << target << ", causing " << this->m_damage << " points of damage!" << std::endl;
        this->m_energy--;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->m_hit <= amount) {
        std::cout << "ClapTrap " << this->m_name << "has died" << std::endl;
        this->m_energy = 0;
        return;
    }
    this->m_hit -= amount;
    std::cout << "ClapTrap " << this->m_name << " was attacked, losing " << amount << " hit points" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
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

void ClapTrap::setDamage(unsigned int damage) {
    this->m_damage = damage;
}

unsigned int  ClapTrap::getDamage(void) {
    return (this->m_damage);
}