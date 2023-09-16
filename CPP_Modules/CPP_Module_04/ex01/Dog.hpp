#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const std::string &name);
        Dog(const Dog &obj);
        ~Dog();
        Dog& operator=(const Dog &obj);
        void makeSound() const;
    private:
        Brain* brain;
};