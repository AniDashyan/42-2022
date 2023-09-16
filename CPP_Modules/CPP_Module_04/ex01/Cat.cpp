#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat construtor" << std::endl;
    this->brain = new Brain();
}

Cat::Cat(const std::string &name) : Animal(name)
{
    this->brain = new Brain();
    std::cout << "Cat param construtor" << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
    this->brain = new Brain(*obj.brain);
    std::cout << "Cat copy construtor" << std::endl;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destrutor" << std::endl;
}

Cat& Cat::operator=(const Cat &obj)
{
    std::cout << "Cat operator= " << std::endl;
    if (this != &obj)
    {
        // delete this->brain;
        this->_type = obj._type;
        *this->brain = *obj.brain;
    }
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "miau" << std::endl;
}