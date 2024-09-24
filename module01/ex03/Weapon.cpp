#include "Weapon.hpp"

        //constructor(s)
Weapon::Weapon(std::string type) : type(type) {}

        //getter(s)
std::string const &Weapon::getType(void) const
{
    return this->type;
}

void Weapon::getType(std::string type)
{
    this->type = type;
}
