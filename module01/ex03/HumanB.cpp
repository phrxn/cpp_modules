#include "HumanB.hpp"

#include <iostream>
#include <cstddef>

HumanB::HumanB(std::string const &name) : name(name){};

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}
void HumanB::attack(void) const
{
    if (this->weapon != NULL && this->weapon->getType() != "")
        std::cout << name << " attacks with their " << this->weapon->getType() << std::endl;
    else
        std::cout << name << " doesn't have a weapon to attack." << std::endl;
}
