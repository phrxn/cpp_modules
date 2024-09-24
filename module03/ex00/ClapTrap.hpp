#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
    private:

        //variables
        std::string     name;
        unsigned int    hitPoints;
        unsigned int    energyPoints;
        unsigned int    attackDamage;

        //constructor
        ClapTrap();

    public:
        //constructor(s) and destructor
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &claptrap);
        ~ClapTrap();

        //operator(s) overload
        ClapTrap &operator=(ClapTrap const &claptrap);

        //others
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};

#endif
