#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    // this->_type = "Dog";
    std::cout << "Dog construtor" << std::endl;
    this->brain = new Brain();
}

Dog::Dog(const std::string &name) : Animal(name)
{
    // this->_type = name;
    this->brain = new Brain();
    std::cout << "Dog param construtor" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
    // this->_type = obj._type;
    this->brain = new Brain(*obj.brain);
    std::cout << "Dog copy construtor" << std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destrutor" << std::endl;
}

Dog& Dog::operator=(const Dog &obj)
{
    std::cout << "Dog operator= " << std::endl;
    if (this != &obj)
    {
        // delete this->brain;
        this->_type = obj._type;
        *this->brain = *obj.brain;
    }
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "miau" << std::endl;
}