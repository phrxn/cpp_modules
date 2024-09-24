#include "Data.hpp"

#ifdef DEBUG
    #include <iostream>
#endif

Data::Data(void)
{
#ifdef DEBUG
    std::cout << "Data: overloaded default constructor called" << std::endl;
#endif
}

Data::Data(const Data &data)
{
#ifdef DEBUG
    std::cout << "Data: overloaded copy constructor called" << std::endl;
#endif
    (void)data;
}

Data::Data(int value, std::string const &name)
{
#ifdef DEBUG
    std::cout << "Data: overloaded value and name constructor called" << std::endl;
#endif
    this->value = value;
    this->name =  name;
}

Data::~Data(void)
{
#ifdef DEBUG
    std::cout << "Data: overloaded destructor called" << std::endl;
#endif
}
    
Data &Data::operator=(const Data &data)
{
#ifdef DEBUG
    std::cout << "Data: overloaded assignment operator called" << std::endl;
#endif
    (void)data;
    return *this;
}

int Data::getValue(void)
{
    return (this->value);
}

void Data::setValue(int value)
{
    this->value = value;
}

std::string const &Data::getName(void)
{
    return (this->name);
}

void Data::setName(std::string const &name)
{
    this->name = name;
}

