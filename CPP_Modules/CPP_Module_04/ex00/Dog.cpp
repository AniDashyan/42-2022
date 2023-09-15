#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Constructor of " << this->m_type << " is called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)  {
    std::cout << "Copy Constructor of Dog is called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        this->m_type = other.m_type;
    }
    return (*this);
}

Dog::~Dog() {
    std::cout << "Destructor of Dog is called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "haf haf" << std::endl;
}