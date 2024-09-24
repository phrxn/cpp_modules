#include "Fixed.hpp"

#include <iostream>
#include <cmath>

//==================== constructor(s) and destructor(s) ==================== 

Fixed::Fixed() : raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::Fixed(const int i) : raw(i << fractional)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f): raw(round(f * (1 << fractional)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

//==================== functions ==================== 

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

float Fixed::toFloat(void) const
{
    return ((float)this->raw / (1 << fractional));
}

int   Fixed::toInt(void) const
{
    return this->raw >> fractional;
}

//==================== operator(s) overload ==================== 

Fixed &Fixed::operator=(const Fixed &fixed)
{
    if (this == &fixed) return *this;

    std::cout << "Copy assignment operator called" << std::endl;

    this->raw = fixed.raw;

    return *this;
}

// ---- logic operators ----
bool  Fixed::operator>(const Fixed &rhs) const
{
    return (this->raw > rhs.raw);
}

bool  Fixed::operator<(const Fixed &rhs) const
{
    return (this->raw < rhs.raw);
}

bool  Fixed::operator>=(const Fixed &rhs) const
{
    return (this->raw >= rhs.raw);
}

bool  Fixed::operator<=(const Fixed &rhs) const
{
    return (this->raw <= rhs.raw);
}

bool  Fixed::operator==(const Fixed &rhs) const
{
    return (this->raw == rhs.raw);
}

bool  Fixed::operator!=(const Fixed &rhs) const
{
    return (this->raw != rhs.raw);
}

// ---- arithmetic operators ---
Fixed Fixed::operator+(Fixed const &rhs) const
{
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
    return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

// ---- increment/decrement operators ----
Fixed &Fixed::operator++(void)
{
    ++(this->raw);
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed fixedTmp(*this);
    ++(*this);
    
    return (fixedTmp);
}

Fixed &Fixed::operator--(void)
{
    --(this->raw);
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed fixedTmp(*this);
    --(*this);
    
    return (fixedTmp);
}

// ---- static functions ----
Fixed &Fixed::min(Fixed &lhs, Fixed &rhs)
{
    if (lhs <= rhs)
        return lhs;
    return rhs;
}

Fixed const &Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
    if (lhs <= rhs)
        return lhs;
    return rhs;
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs)
{
    if (lhs >= rhs)
        return lhs;
    return rhs;
}

Fixed const &Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
    if (lhs >= rhs)
        return lhs;
    return rhs;
}


// ---- output to Fixed ----
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}
