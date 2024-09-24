#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

#include <iostream>

// --- constructor(s) and destructor ---
WrongCat::WrongCat(void) : WrongAnimal()
{
    std::cout << "WrongCat: overloaded default constructor called" << std::endl;
    this->type = "Wrong Cat";
}

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal()
{
    std::cout << "WrongCat: overloaded copy constructor called" << std::endl;
    *this = wrongCat;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat: overloaded destructor called" << std::endl;
}

//operator(s) overload
WrongCat &WrongCat::operator=(const WrongCat &wrongCat)
{
    std::cout << "WrongCat: overloaded assignment operator called" << std::endl;
    if (this == &wrongCat) return *this;

    this->type = wrongCat.type;

    return *this;
}

//others
void WrongCat::makeSound(void) const
{
    std::cout << "The WrongAnimal( " << this->type << ") made: " << "Meow!" << std::endl;
}
