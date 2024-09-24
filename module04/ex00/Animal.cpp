#include "Animal.hpp"

#include <iostream>

// --- constructor(s) and destructor ---
Animal::Animal(void) : type ("-- generic animal, not type --")
{
    std::cout << "Animal: overloaded default constructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
    std::cout << "Animal: overloaded copy constructor called" << std::endl;
    *this = animal;
}

Animal::~Animal()
{
    std::cout << "Animal: overloaded destructor called" << std::endl;
}

//operator(s) overload
Animal &Animal::operator=(const Animal &animal)
{
    std::cout << "Animal: overloaded assignment operator called" << std::endl;
    if (this == &animal) return *this;

    this->type = animal.type;

    return *this;
}

//getter(s)
std::string Animal::getType(void) const
{
    return this->type;
}

//others
void Animal::makeSound(void) const
{
    std::cout << "-- generic animal, not sound --" << std::endl;
}
