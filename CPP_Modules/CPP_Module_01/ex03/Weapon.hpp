#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
    private:
        std::string type;
    public:
        Weapon(std::string _type);
        std::string getType();
        void setType(std::string type);
        ~Weapon();
};

#endif