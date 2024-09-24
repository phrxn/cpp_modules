#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"

#include <string>

class HumanB
{
    //variables
    private:
        std::string name;
        Weapon *weapon;

    public:
        HumanB(std::string const &name);

        //setter(s)
        void setWeapon(Weapon &weapon);

        //function(s)
        void attack(void) const;
};

#endif
