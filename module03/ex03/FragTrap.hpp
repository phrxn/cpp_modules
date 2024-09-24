#ifndef FragTrap_HPP
#define FragTrap_HPP

#include "ClapTrap.hpp"

#include <string>

class FragTrap : virtual public ClapTrap
{
    public:
        //static values
        static const int DEFAULT_HIT_POINTS = 100;
        static const int DEFAULT_ENERGY_POINTS = 100;
        static const int DEFAULT_ATTACK_DAMAGE = 30;

        //constructor(s) and destructor
        FragTrap(std::string name);
        FragTrap(FragTrap const &src);
        ~FragTrap(void);

        //operator(s) overload
        FragTrap &operator=(FragTrap const &FragTrap);

        //functions
        void highFivesGuys(void);
    
    protected:
        //constructor
        FragTrap(void);
};

#endif
