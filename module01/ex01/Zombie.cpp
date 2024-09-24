#include "Zombie.hpp"

#include <string>
#include <iostream>

Zombie::Zombie(const std::string &name)
              :
              name(name){};

Zombie::~Zombie()
{
    std::cout << "the zombie: " << this->name << " dead! ... don't wait o.O!" << std::endl;
}

void Zombie::setName(const std::string &name)
{
    this->name = name;
}

void Zombie::announce(void) const
{
   std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
