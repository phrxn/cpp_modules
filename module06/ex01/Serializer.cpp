#include "Serializer.hpp"

#include <cstdlib>
#ifdef DEBUG
    #include <iostream> 
#endif

Serializer::Serializer(void)
{
#ifdef DEBUG
    std::cout << "Serializer: overloaded default constructor called" << std::endl;
#endif
}

Serializer::Serializer(const Serializer &scalarConverter)
{
#ifdef DEBUG
    std::cout << "Serializer: overloaded copy constructor called" << std::endl;
#endif
    (void)scalarConverter;
}

Serializer::~Serializer(void)
{
#ifdef DEBUG
    std::cout << "Serializer: overloaded destructor called" << std::endl;
#endif
}
    
Serializer &Serializer::operator=(const Serializer &scalarConverter)
{
#ifdef DEBUG
    std::cout << "Serializer: overloaded assignment operator called" << std::endl;
#endif
    (void)scalarConverter;
    return *this;
}

uintptr_t    Serializer::serialize(Data *data)
{
    return (reinterpret_cast<uintptr_t>(data));
}
Data         *Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}
