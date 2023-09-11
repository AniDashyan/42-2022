#include "ScavTrap.hpp"

int main() {
    ScavTrap st1("A");
    ScavTrap st2("B");

    st1.setDamage(5);
    st2.setDamage(3);

    st1.attack("B");
    st2.takeDamage(st1.getDamage());
    st2.beRepaired(3);
    st1.guardGate();
    st2.attack("A");
    st2.guardGate();
    st1.takeDamage(st2.getDamage());
    st1.beRepaired(10);
    return (0);
}