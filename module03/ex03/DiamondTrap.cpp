#include "DiamondTrap.hpp"

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap(){}

DiamondTrap::DiamondTrap(std::string name) :
    ClapTrap(name),
    ScavTrap(name),
    FragTrap(name),
    name(name)
{
    this->ClapTrap::name = name + "_clap_name";
    hitPoints = FragTrap::DEFAULT_HIT_POINTS;
    energyPoints = ScavTrap::DEFAULT_ENERGY_POINTS;
    attackDamage = FragTrap::DEFAULT_ATTACK_DAMAGE;

    std::cout << "DiamondTrap: Constructor name called [" << name << "]" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) :
    ClapTrap(""),
    ScavTrap(""),
    FragTrap(""),
    name("")
{
    *this = diamondTrap;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap: destructor called [" << this->name << "]" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
    if (this == &diamondTrap) return *this;

    this->name = diamondTrap.name;
    this->hitPoints = diamondTrap.hitPoints;
    this->energyPoints = diamondTrap.energyPoints;
    this->attackDamage = diamondTrap.attackDamage;

    return *this;
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamonTrap: I'm " << this->name << " and my grandpa is " << this->ClapTrap::name << std::endl;
}
