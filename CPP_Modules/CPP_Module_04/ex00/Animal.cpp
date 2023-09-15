#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Constructor of Animal is called" << std::endl;
}

Animal::Animal(std::string type) : m_type(type) {
     std::cout << "Constructor with parameters of Animal " << this->m_type << " is called" << std::endl;
}

Animal::Animal(const Animal& other) : m_type(other.m_type) {
    std::cout << "Copy Constructor of Animal is called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        this->m_type = other.m_type;
    }
    std::cout << "Copy Assignment Operator of Animal is called" << std::endl;
    return (*this);
}

Animal::~Animal() {
    std::cout << "Destructor of Animal is called" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "sound sound" << std::endl;
}

std::string Animal::getType(void) const {
    return (this->m_type);
}