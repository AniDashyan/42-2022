#pragma once
#include <iostream>

class Animal
{
    public:
        Animal();
        Animal(const std::string &name);
        Animal(const Animal &obj);
        virtual ~Animal();
        Animal& operator=(const Animal &obj);
        virtual void makeSound() const = 0;
        void setType(const std::string &type);
        std::string getType() const;
    protected:
        std::string _type;
};