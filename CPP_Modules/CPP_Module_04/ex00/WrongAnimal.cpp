#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("name")
{
    std::cout << "WrongAnimal constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &name) : _type(name)
{
    std::cout << "WrongAnimal param constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) : _type(obj._type)
{
    // this->_type = obj._type;
    std::cout << "WrongAnimal copy constructor" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &obj)
{
    if (this != &obj)
        this->_type = obj._type;
    std::cout << "WrongAnimal operator=" << std::endl;
    return (*this);
}

void WrongAnimal::makeSound() const 
{
    std::cout << "WrongAnimal sound" << std::endl;
}


void WrongAnimal::setType(const std::string &type)
{
    this->_type = type;
}

std::string WrongAnimal::getType() const
{
    return (_type);
}