#include "ClapTrap.hpp"

#include <string>
#include <iostream>

int main(void)
{
    std::string name1("XT-900");
    std::string name2("Zeus");

    ClapTrap clapTrap1(name1);
    ClapTrap clapTrap2(name2);

    clapTrap1.attack(name2);
    clapTrap1.beRepaired(2);

    for(int count = 0; count < 10; count++)
    {
        clapTrap1.attack(name2);
    }

    std::cout << "\n----------\n" << std::endl;

    for(int count = 0; count < 10; count++)
    {
        clapTrap2.takeDamage(count);
    }

    std::cout << "\n----------\n" << std::endl;


    clapTrap1.beRepaired(2);
    return 0;
}
