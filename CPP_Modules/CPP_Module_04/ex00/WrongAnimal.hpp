#pragma once
#include <iostream>
class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(const std::string &name);
        WrongAnimal(const WrongAnimal &obj);
        ~WrongAnimal();
        WrongAnimal& operator=(const WrongAnimal &obj);
        void makeSound() const;
        void setType(const std::string &type);
        std::string getType() const;
    protected:
        std::string _type;
};