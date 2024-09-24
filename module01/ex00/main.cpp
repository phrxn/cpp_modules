#include "Zombie.hpp"

#include <string>
#include <iostream>

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
    std::cout << "Creating a zombie (Stackbie) on the stack." << std::endl;
    std::cout << std::endl;
    Zombie zombieStack("Stackbie");

    std::cout << "Calling randomChump() and creating a \"temporary\" zombie inside randomChump()" << std::endl;
    randomChump("ChumpZZ");
    std::cout << std::endl;

    
    std::cout << "Create tree zombies on the heap." << std::endl;
    Zombie *firstZombie = newZombie("Eddie");
    Zombie *secondZombie = newZombie("Exodia Necross");
    Zombie *thirdZombie = newZombie("Saddler");
    firstZombie->announce();
    secondZombie->announce();
    thirdZombie->announce();
    std::cout << std::endl;

    std::cout << "Deleting the three zombies from the heap!" << std::endl;
    delete firstZombie;
    delete secondZombie;
    delete thirdZombie;

    std::cout << std::endl;
    std::cout << "Now, the Stackbie zombie will be destroyed before main returns!" << std::endl;

    return 0;
}
