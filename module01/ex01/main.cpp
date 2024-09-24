#include "Zombie.hpp"

#include <string>
#include <iostream>

# define HORDER_NUMBER 10

Zombie *zombieHorder(int N, std::string name);

int main(void)
{
    std::cout << "Creating a zombie horder! With " << HORDER_NUMBER << " zombies" << std::endl;
    Zombie *horder = zombieHorder(HORDER_NUMBER, "Nemesis");

    if (!horder)
    {
        std::cout << "The zombie horder allocation fail!" << std::endl;
        return 1;
    }

    for (int count = 0; count < HORDER_NUMBER; count++)
        horder[count].announce();
    
    std::cout << std::endl;

    std::cout << "Goodbye, horder!" << std::endl;
    delete [] horder;
    return 0;
}
