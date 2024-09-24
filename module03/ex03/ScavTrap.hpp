#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#include <string>

class ScavTrap : virtual public ClapTrap
{
    public:
        //static values
        static const int DEFAULT_HIT_POINTS = 100;
        static const int DEFAULT_ENERGY_POINTS = 50;
        static const int DEFAULT_ATTACK_DAMAGE = 20;

        //constructor(s) and destructor
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &src);
        ~ScavTrap(void);

        //operator(s) overload
        ScavTrap &operator=(ScavTrap const &scavTrap);

        //functions
        void attack(const std::string &target);
        void guardGate(void);
    
    protected:
        //constructor
        ScavTrap(void);
};

#endif
