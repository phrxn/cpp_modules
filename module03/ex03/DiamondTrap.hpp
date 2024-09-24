#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
    //variables
    private:
        std::string name;

    //functions
    public:
        //constructor(s) and destructor
        DiamondTrap(std::string strName);
        DiamondTrap(const DiamondTrap &diamondTrap);
        ~DiamondTrap();

        //operator(s) overload
        DiamondTrap &operator=(const DiamondTrap &diamondTrap);

        //functions
        using ScavTrap::attack;
        void whoAmI(void);

    private:
        DiamondTrap(void);
};

#endif
