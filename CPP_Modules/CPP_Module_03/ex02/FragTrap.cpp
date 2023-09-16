#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {
    this->m_hit = 100;
    this->m_energy = 100;
    this->m_damage = 30;
    std::cout << "Constructor of FragTrap " << this->m_name << " is called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
    this->m_name = name;
    this->m_hit = 100;
    this->m_energy = 100;
    this->m_damage = 30;
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
    if (this != &other)
    {
        this->m_name = other.m_name;
        this->m_hit = other.m_hit;
        this->m_energy = other.m_energy;
        this->m_damage = other.m_damage;
    }
    std::cout << "Copy Assignment Operator of FragTrap " << this->m_name  << " is called" << std::endl;
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << "Destructor of FragTrap " << this->m_name << " is called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    if (this->m_hit > 0 && this->m_energy > 0)
    {
       std::cout << "Hey there! How about a positive high five to celebrate our awesome day?" << std::endl;
    }
    else
        std::cout << "Sorry. FragTrap " << this->m_name << " can't high five" << std::endl;
}