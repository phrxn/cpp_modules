#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "Weapon.hpp"

#include <string>

class HumanA
{
    //variables
    private:
        std::string const name;
        Weapon const &weapon;

    public:
        HumanA(std::string const &name, Weapon const &weapon);

        //function(s)
        void attack(void) const;
};

#endif

