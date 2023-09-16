#include "ClapTrap.hpp"

int main() {
    ClapTrap obj("Jack");
    ClapTrap obj_2("Supermarket");
   
    obj.setDamage(5);
    obj.attack("Supermarket");
    obj_2.takeDamage(obj.getDamage());
    obj_2.beRepaired(3);
    obj.attack("Supermarket");
    obj_2.takeDamage(obj.getDamage());
    obj.attack("Supermarket");
    obj_2.takeDamage(obj.getDamage());
    obj_2.beRepaired(3);
    obj_2.attack("Jack");
    obj.takeDamage(obj.getDamage());
    return (0);
}