#include "Dog.hpp"
#include "Animal.hpp"

#include <iostream>

// --- constructor(s) and destructor ---
Dog::Dog(void) : Animal()
{
    std::cout << "Dog: overloaded default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &dog) : Animal()
{
    std::cout << "Dog: overloaded copy constructor called" << std::endl;
    *this = dog;
}

Dog::~Dog()
{
    std::cout << "Dog: overloaded destructor called" << std::endl;
}

//operator(s) overload
Dog &Dog::operator=(const Dog &dog)
{
    std::cout << "Dog: overloaded assignment operator called" << std::endl;
    if (this == &dog) return *this;

    this->type = dog.type;

    return *this;
}

//others
void Dog::makeSound(void) const
{
    std::cout << "The Animal (" << this->type << ") made: " << "Ruf Ruf!" << std::endl;
}
