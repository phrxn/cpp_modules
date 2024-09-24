#include "Cat.hpp"
#include "Animal.hpp"

#include <iostream>

// --- constructor(s) and destructor ---
Cat::Cat(void) : Animal()
{
    std::cout << "Cat: overloaded default constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &cat) : Animal()
{
    std::cout << "Cat: overloaded copy constructor called" << std::endl;
    *this = cat;
}

Cat::~Cat()
{
    std::cout << "Cat: overloaded destructor called" << std::endl;
}

//operator(s) overload
Cat &Cat::operator=(const Cat &cat)
{
    std::cout << "Cat: overloaded assignment operator called" << std::endl;
    if (this == &cat) return *this;

    this->type = cat.type;

    return *this;
}

//others
void Cat::makeSound(void) const
{
    std::cout << "The Animal (" << this->type << ") made: " << "Meow!" << std::endl;
}
