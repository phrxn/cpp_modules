#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

#include <string>
#include <iostream>

int main(void)
{
    DiamondTrap diamondTrapTest1("DT-001");

    std::cout << "\n**who am I? ... call from diamondTrap" << std::endl;
    diamondTrapTest1.whoAmI();

    std::cout << "\n**attack ... call from scavtrap" << std::endl;

    diamondTrapTest1.attack("Other clap");

    std::cout << "\n**new call from claptrap" << std::endl;
    diamondTrapTest1.takeDamage(30);
    diamondTrapTest1.beRepaired(10);

    std::cout << std::endl;

    return (0);
}
