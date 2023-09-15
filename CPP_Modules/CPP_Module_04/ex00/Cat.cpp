#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Constructor of " << this->m_type << " is called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)  {
    // this->m_type = other.m_type;
    std::cout << "Copy Constructor of Cat is called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        this->m_type = other.m_type;
    }
    return (*this);
}

Cat::~Cat() {
    std::cout << "Destructor of Cat is called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "tekuz" << std::endl;
}