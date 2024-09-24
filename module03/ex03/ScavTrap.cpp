#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap(){}

ScavTrap::ScavTrap(std::string name)
    : ClapTrap(name)
{
    hitPoints = DEFAULT_HIT_POINTS;
    energyPoints = DEFAULT_ENERGY_POINTS;
    attackDamage = DEFAULT_ATTACK_DAMAGE;

    std::cout << "ScavTrap: Constructor name called [" << name << "]" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap()
{
    *this = src;
    std::cout << "ScavTrap: Constructor copy called [" << this->name << "]" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap: destructor called [" << this->name << "]" << std::endl;
}

//operator(s) overload
ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
    if (this == &scavTrap) return *this;

    this->name = scavTrap.name;
    this->hitPoints = scavTrap.hitPoints;
    this->energyPoints = scavTrap.energyPoints;
    this->attackDamage = scavTrap.attackDamage;

    return *this;
}

void ScavTrap::attack(const std::string &target)
{

    if (this->hitPoints == 0)
    {
        std::cout << "ScavTrap " << this->name << " can't attack: it is die." << std::endl;
        return ;
    }
    if (this->energyPoints == 0)
    {
        std::cout << "ScavTrap " << this->name << " can't attack: its battery is empty!" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", cousing " << this->attackDamage << " points of damage!" << std::endl;
    this->energyPoints -= 1;
}

void ScavTrap::guardGate(void)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ScavTrap " << this->name << " can't guard the gate: it is die." << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->name << "is guard the gates" << std::endl;
}
