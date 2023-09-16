#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const std::string &name);
        WrongCat(const WrongCat &obj);
        ~WrongCat();
        WrongCat& operator=(const WrongCat &obj);
        void makeSound() const;
};