#include "Dog.hpp"
#include "AAnimal.hpp"
#include "Brain.hpp"

#include <iostream>

// --- constructor(s) and destructor ---
Dog::Dog(void) : AAnimal(), brain(new Brain())
{
    std::cout << "Dog: overloaded default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &dog) : AAnimal(), brain(new Brain())
{
    std::cout << "Dog: overloaded copy constructor called" << std::endl;
    *this = dog;
}

Dog::~Dog()
{
    std::cout << "Dog: overloaded destructor called" << std::endl;
    delete brain;
}

//operator(s) overload
Dog &Dog::operator=(const Dog &dog)
{
    std::cout << "Dog: overloaded assignment operator called" << std::endl;
    if (this == &dog) return *this;

    this->type = dog.type;
    *(this->brain) = *(dog.brain);

    return *this;
}

//others
void Dog::makeSound(void) const
{
    std::cout << "The AAnimal (" << this->type << ") made: " << "Ruf Ruf!" << std::endl;
}

Brain &Dog::getBrain(void)
{
    return *this->brain;
}
