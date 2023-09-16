#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    // this->_type = "WrongCat";
    std::cout << "WrongCat construtor" << std::endl;
}

WrongCat::WrongCat(const std::string &name) : WrongAnimal(name)
{
    // this->_type = name;
    std::cout << "WrongCat param construtor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
    // this->_type = obj._type;
    std::cout << "WrongCat copy construtor" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destrutor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &obj)
{
    if (this != &obj)
        this->_type = obj._type;
    std::cout << "WrongCat operator= " << std::endl;
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "miau" << std::endl;
}