#include "FragTrap.hpp"
#include "ClapTrap.hpp"

#include <iostream>

FragTrap::FragTrap(){}

FragTrap::FragTrap(std::string name)
    : ClapTrap(name)
{
    hitPoints = DEFAULT_HIT_POINTS;
    energyPoints = DEFAULT_ENERGY_POINTS;
    attackDamage = DEFAULT_ATTACK_DAMAGE;

    std::cout << "FragTrap: Constructor name called [" << name << "]" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap()
{
    *this = src;
    std::cout << "FragTrap: Constructor copy called [" << this->name << "]" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap: Destructor called [" << this->name << "]" << std::endl;
}

//operator(s) overload
FragTrap &FragTrap::operator=(const FragTrap &FragTrap)
{
    if (this == &FragTrap) return *this;

    this->name = FragTrap.name;
    this->hitPoints = FragTrap.hitPoints;
    this->energyPoints = FragTrap.energyPoints;
    this->attackDamage = FragTrap.attackDamage;

    return *this;
}

void FragTrap::highFivesGuys(void)
{
    if (this->hitPoints == 0)
    {
        std::cout << "FragTrap: " << this->name << " can't high fives: it is die." << std::endl;
        return ;
    }
    if (this->energyPoints == 0)
    {
        std::cout << "FragTrap: " << this->name << " can't high fives: its battery is empty!" << std::endl;
        return ;
    }
    std::cout << "FragTrap: "  << this->name <<  " Hello! High fives everybody." << std::endl;
}

