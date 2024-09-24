#include "AAnimal.hpp"

#include <iostream>

// --- constructor(s) and destructor ---
AAnimal::AAnimal(void) : type ("-- generic aanimal, not type --")
{
    std::cout << "AAnimal: overloaded default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &aanimal)
{
    std::cout << "AAnimal: overloaded copy constructor called" << std::endl;
    *this = aanimal;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal: overloaded destructor called" << std::endl;
}

//operator(s) overload
AAnimal &AAnimal::operator=(const AAnimal &aanimal)
{
    std::cout << "AAnimal: overloaded assignment operator called" << std::endl;
    if (this == &aanimal) return *this;

    this->type = aanimal.type;

    return *this;
}

//getter(s)
std::string AAnimal::getType(void) const
{
    return this->type;
}

//others
void AAnimal::makeSound(void) const
{
    std::cout << "-- generic aanimal, not sound --" << std::endl;
}
