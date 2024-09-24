#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include <string>
#include <iostream>

int main(void)
{
    std::string scavTrapHitName = "scav The hit";
    ScavTrap scavTrapHitTest(scavTrapHitName);

    std::cout << "\n      ***ScavTrap teste hit" << std::endl;

    for(int count = 0; count < ScavTrap::DEFAULT_HIT_POINTS; count+=25)
    {
        scavTrapHitTest.takeDamage(25);
    }
    std::cout << std::endl;
    std::cout << std::endl;
    
    std::string scavTrapAttackName = "scav Attacker!!";
    ScavTrap scavTrapAttack(scavTrapAttackName);
    scavTrapAttack.attack("scav The hit");
    scavTrapHitTest.takeDamage(ScavTrap::DEFAULT_ATTACK_DAMAGE);

    std::cout << "\n      ***ScavTrap guardGate test" << std::endl;

    std::string scavTrapGuardName = "scav Guard";
    ScavTrap scavTrapGuard(scavTrapGuardName);
    scavTrapGuard.guardGate();

    std::cout << "\n" << std::endl;

    std::cout << "\n      ***Constructor and destructor test" << std::endl;
    std::cout << "ClapTrap only" << std::endl;
    std::string clapTrapTestName = " 1) ClapTrapName";
    ClapTrap clapTrapTest(clapTrapTestName);
    std::cout << std::endl;
    std::cout << "ScavTrap only" << std::endl;
    std::string scavTrapTestName = " 2) scavTrapTestName";
    ScavTrap scavTrapTest(scavTrapTestName);
    std::cout << std::endl;
    



    std::cout << "\n" << std::endl;

    return 0;

    /*

    clapTrap.attack(scavTrapName);
    scavTrap.takeDamage(20);
    scavTrap.attack(clapTrapName);
    clapTrap.takeDamage(89);
    clapTrap.beRepaired(5000);
    scavTrap.guardGate();
    for (int i = 0; i < 50; i++)
        scavTrap.beRepaired(5000);
    scavTrap.attack(scavTrapName);
    scavTrap.guardGate();
    scavTrap.takeDamage(5000);

    */
    return (0);
}
