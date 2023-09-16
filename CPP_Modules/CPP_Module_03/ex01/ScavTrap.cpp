#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {
    this->m_hit = 100;
    this->m_energy = 50;
    this->m_damage = 20;
    std::cout << "Constructor of ScavTrap " << this->m_name << " is called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name) {
    this->m_name = name;
    this->m_hit = 100;
    this->m_energy = 50;
    this->m_damage = 20;
    std::cout << "Constructor of ScavTrap " << this->m_name << " is called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) {
    this->m_name = other.m_name;
    this->m_hit = other.m_hit;
    this->m_energy = other.m_energy;
    this->m_damage = other.m_damage;
    std::cout << "Copy Constructor of ScavTrap " << this->m_name << " is called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other)
    {
        this->m_name = other.m_name;
        this->m_hit = other.m_hit;
        this->m_energy = other.m_energy;
        this->m_damage = other.m_damage;
    }
    std::cout << "Copy Assignment Operator of ScavTrap " << this->m_name  << " is called" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap() {
    std::cout << "Destructor of ScavTrap " << this->m_name << " is called!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (this->m_hit <= 0)
        std::cout << "ScavTrap " << this->m_name << " has died. Can't attack" << std::endl;
    else if (this->m_energy <= 0)
            std::cout << "ScavTrap " << this->m_name << " ran out of energy. Can't do anything" << std::endl;
    else {
        std::cout << "ScavTrap " << this->m_name << " attacks " << target << ", causing " << this->m_damage << " points of damage!" << std::endl;
        this->m_energy--;
    }
}

void ScavTrap::guardGate() {
    if (this->m_hit > 0 && this->m_energy > 0)
    {
        std::cout << "ScavTrap " << this->m_name << " has entered Gate Keeper Mode" << std::endl;
    }
    else
        std::cout << "ScavTrap " << this->m_name << " can't enter Gate Keeper Mode" << std::endl;
}