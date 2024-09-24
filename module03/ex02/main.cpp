#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <string>
#include <iostream>

int main(void)
{
    std::string fragTrapHighFivesName = "frag hello";
    FragTrap fragTrapHighFives(fragTrapHighFivesName);
    fragTrapHighFives.highFivesGuys();

    std::cout << "\n" << std::endl;

    std::string scavTrapBadName = "bad scavTrap";
    ScavTrap scavTrapBad(scavTrapBadName);

    scavTrapBad.attack(fragTrapHighFivesName);
    fragTrapHighFives.takeDamage(ScavTrap::DEFAULT_ATTACK_DAMAGE);
    scavTrapBad.attack(fragTrapHighFivesName);
    fragTrapHighFives.takeDamage(ScavTrap::DEFAULT_ATTACK_DAMAGE);
    scavTrapBad.attack(fragTrapHighFivesName);
    fragTrapHighFives.takeDamage(ScavTrap::DEFAULT_ATTACK_DAMAGE);
    scavTrapBad.attack(fragTrapHighFivesName);
    fragTrapHighFives.takeDamage(ScavTrap::DEFAULT_ATTACK_DAMAGE);

    std::cout << std::endl;
    fragTrapHighFives.highFivesGuys();
    std::cout << std::endl;

    scavTrapBad.attack(fragTrapHighFivesName);
    fragTrapHighFives.takeDamage(ScavTrap::DEFAULT_ATTACK_DAMAGE);

    std::cout << std::endl;
    fragTrapHighFives.highFivesGuys();
    std::cout << std::endl;

    return (0);
}
