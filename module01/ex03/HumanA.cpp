#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(std::string const &name, Weapon const &weapon) :
               name(name), weapon(weapon){};

void HumanA::attack(void) const
{
    if (this->weapon.getType() != "")
        std::cout << name << " attacks with their " << this->weapon.getType() << std::endl;
    else
        std::cout << name << " doesn't have a weapon to attack." << std::endl;
}
