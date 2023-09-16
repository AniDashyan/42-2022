#include "Animal.hpp"

Animal::Animal() : _type("name")
{
    std::cout << "Animal constructor" << std::endl;
}

Animal::Animal(const std::string &name) : _type(name)
{
    std::cout << "Animal param constructor" << std::endl;
}

Animal::Animal(const Animal &obj) : _type(obj._type)
{
    // this->_type = obj._type;
    std::cout << "Animal copy constructor" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor" << std::endl;
}

Animal& Animal::operator=(const Animal &obj)
{
    if (this != &obj)
        this->_type = obj._type;
    std::cout << "Animal operator=" << std::endl;
    return (*this);
}

void Animal::makeSound() const 
{
    std::cout << "Animal sound" << std::endl;
}


void Animal::setType(const std::string &type)
{
    this->_type = type;
}

std::string Animal::getType() const
{
    return (_type);
}