#include "Zombie.hpp"

#include <string>

Zombie *newZombie(std::string name)
{
    Zombie *newZombiez = new Zombie(name);
    return (newZombiez);
}
