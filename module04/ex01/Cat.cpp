#include "Cat.hpp"
#include "Animal.hpp"

#include <iostream>

// --- constructor(s) and destructor ---
Cat::Cat(void) : Animal(), brain(new Brain())
{
    std::cout << "Cat: overloaded default constructor called" << std::endl;
    this->type = "Cat";
//    this->brain = new Brain();
}

Cat::Cat(const Cat &cat) : Animal(), brain(new Brain())
{
    std::cout << "Cat: overloaded copy constructor called" << std::endl;
//    this->brain = new Brain();
    *this = cat;
}

Cat::~Cat()
{
    std::cout << "Cat: overloaded destructor called" << std::endl;
    delete brain;
}

//operator(s) overload
Cat &Cat::operator=(const Cat &cat)
{
    std::cout << "Cat: overloaded assignment operator called" << std::endl;
    if (this == &cat) return *this;

    this->type = cat.type;
    *(this->brain) = *(cat.brain);

    return *this;
}

//others
void Cat::makeSound(void) const
{
    std::cout << "The Animal (" << this->type << ") made: " << "Meow!" << std::endl;
}

Brain &Cat::getBrain(void)
{
    return *this->brain;
}
