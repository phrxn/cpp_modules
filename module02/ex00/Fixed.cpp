#include "Fixed.hpp"

#include <iostream>

//constructor(s) and destructor(s)
Fixed::Fixed() : raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
        //functions
int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;

    return this->raw;
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;

    this->raw = raw;
}

//operator(s) overload

Fixed &Fixed::operator=(const Fixed &fixed)
{
    if (this == &fixed) return *this;

    std::cout << "Copy assignment operator called" << std::endl;

    this->raw = fixed.getRawBits();

    return *this;
}

