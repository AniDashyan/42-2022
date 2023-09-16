#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor" << std::endl;
}
Brain::Brain(const Brain &obj)
{
    for (size_t i = 0; i < 100; ++i)
    {
        this->_ideas[i] = obj._ideas[i]; //??
    }
    std::cout << "Brain copy constructor" << std::endl;
}

Brain&Brain:: operator=(const Brain &obj)
{
    if (this != &obj)
    {
        for (size_t i = 0; i < 100; ++i)
        {
            this->_ideas[i] = obj._ideas[i]; //??
        }
    }
    std::cout << "Brain operator=" << std::endl;
    return (*this);
}
Brain::~Brain()
{
    std::cout << "Brain destructor" << std::endl;
}