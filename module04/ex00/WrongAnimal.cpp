#include "WrongAnimal.hpp"

#include <iostream>

// --- constructor(s) and destructor ---
WrongAnimal::WrongAnimal(void) : type ("-- generic wrongAnimal, not type --")
{
    std::cout << "WrongAnimal: overloaded default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
{
    std::cout << "WrongAnimal: overloaded copy constructor called" << std::endl;
    *this = wrongAnimal;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal: overloaded destructor called" << std::endl;
}

//operator(s) overload
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal)
{
    std::cout << "WrongAnimal: overloaded assignment operator called" << std::endl;
    if (this == &wrongAnimal) return *this;

    this->type = wrongAnimal.type;

    return *this;
}

//getter(s)
std::string WrongAnimal::getType(void) const
{
    return this->type;
}

//others
void WrongAnimal::makeSound(void) const
{
    std::cout << "-- generic wrongAnimal, not sound --" << std::endl;
}
