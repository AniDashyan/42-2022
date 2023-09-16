#include "ScavTrap.hpp"

int main() {
    ClapTrap obj("obj");
    ScavTrap obj_2("obj_2");

    obj.setDamage(41);
    obj.attack("obj_2");
    obj_2.takeDamage(obj.getDamage());
    obj_2.beRepaired(12);
    obj.attack("obj_2");
    obj_2.guardGate();
    obj_2.takeDamage(10);
    obj.attack("obj_2");
    obj_2.takeDamage(obj.getDamage());
    obj.attack("obj_2");
    obj_2.takeDamage(9);
    obj_2.attack("obj");
    obj.attack("obj_2");
    obj_2.guardGate();
  
    return (0);
}