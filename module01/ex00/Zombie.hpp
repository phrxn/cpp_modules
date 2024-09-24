#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
    //private variables
    private:
        std::string name;

    public:
        //constructor(s) and destructor
        Zombie(const std::string &name);
        ~Zombie();

        //methods
        void announce(void) const;
};
#endif
