#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
    //variables
    private:
        std::string type;

    public:
        //constructor(s)
        Weapon(std::string type);

        //getter(s)
        std::string const &getType(void) const;
        void getType(std::string type);
};

#endif
