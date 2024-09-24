#include "ClapTrap.hpp"

#include <iostream>


//constructor(s) and destructor
ClapTrap::ClapTrap() 
    : name(""),
    hitPoints(DEFAULT_HIT_POINTS),
    energyPoints(DEFAULT_ENERGY_POINTS),
    attackDamage(DEFAULT_ATTACK_DAMAGE)
{
}

ClapTrap::ClapTrap(std::string name)
    : name(name),
    hitPoints(DEFAULT_HIT_POINTS),
    energyPoints(DEFAULT_ENERGY_POINTS),
    attackDamage(DEFAULT_ATTACK_DAMAGE)
{
    std::cout << "ClapTrap: Constructor name called [" << name << "]" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &claptrap)
{
    *this = claptrap;
    std::cout << "ClapTrap: Constructor copy called [" << this->name << "]" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap: destructor called [" << this->name << "]" << std::endl;
}

//operator(s) overload
ClapTrap &ClapTrap::operator=(ClapTrap const &claptrap)
{
    if (this == &claptrap) return *this;

    this->name = claptrap.name;
    this->hitPoints = claptrap.hitPoints;
    this->energyPoints = claptrap.energyPoints;
    this->attackDamage = claptrap.attackDamage;

    return *this;
}

//others
void ClapTrap::attack(const std::string &target)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " can't attack: it is die." << std::endl;
        return ;
    }
    if (this->energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " can't attack: its battery is empty!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", cousing " << this->attackDamage << " points of damage!" << std::endl;
    this->energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
        return ;
    }

    //calc new hitPoints
    if (this->hitPoints <= amount)
        this->hitPoints = 0;
    else
        this->hitPoints -= amount;
   
    //show the message
    if (this->hitPoints == 0)
        std::cout << "ClapTrap " << this->name << " takes " << amount << " damage and die!" << std::endl;
    else
        std::cout << "ClapTrap " << this->name << " takes " << amount << " damage." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " can't repair itself: it is die." << std::endl;
        return ;
    }
    if (this->energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " can't repair itself: is out of energy!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " repairs itself for " << amount << " hit points!" << std::endl;
    this->energyPoints -= 1;
    this->hitPoints += amount;
}

