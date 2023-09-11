#include "ClapTrap.hpp"

int main() {
    ClapTrap ct1("A");
    ClapTrap ct2("B");

    ct1.setDamage(5);
    ct2.setDamage(10);

    ct1.attack("B");
    ct2.takeDamage(ct1.getDamage());
    ct2.beRepaired(3);
    ct2.attack("A");
    ct1.takeDamage(ct2.getDamage());
    ct1.beRepaired(10);
    return (0);
}