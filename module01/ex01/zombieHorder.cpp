#include "Zombie.hpp"
#include <cstddef>

Zombie *zombieHorder(int N, std::string name)
{
    if(!N)
        return NULL;

    Zombie *zombieApocalypse = new Zombie[N];
    if (!zombieApocalypse)
        return NULL;

    for(int count=0; count < N; count++)
        zombieApocalypse[count].setName(name);
    return zombieApocalypse;
}
