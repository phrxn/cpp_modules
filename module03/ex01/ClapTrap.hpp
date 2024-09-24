#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
    protected:

        //variables
        std::string     name;
        unsigned int    hitPoints;
        unsigned int    energyPoints;
        unsigned int    attackDamage;

        //constructor
        ClapTrap(void);

    public:
        //static values
        static const int DEFAULT_HIT_POINTS = 10;
        static const int DEFAULT_ENERGY_POINTS = 10;
        static const int DEFAULT_ATTACK_DAMAGE = 0;

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
