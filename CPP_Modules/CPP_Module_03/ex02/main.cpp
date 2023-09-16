#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    FragTrap obj("obj");
    FragTrap obj_2("obj_2");

    obj_2.highFivesGuys();
    obj.setDamage(42);
    obj.attack("obj_2");
    obj_2.takeDamage(20);
    obj_2.beRepaired(15);
    obj.attack("obj_2");
    obj_2.takeDamage(3);
    obj.attack("obj_2");
    obj_2.takeDamage(2);
    obj.attack("obj_2");
    obj_2.takeDamage(10);
    obj_2.attack("obj");
    obj.attack("obj_2");
    obj_2.highFivesGuys();
  
    return (0);
}