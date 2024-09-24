#include "Brain.hpp"

#include <iostream>

// --- constructor(s) and destructor ---
Brain::Brain(void)
{
    std::cout << "Brain: overloaded default constructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
    std::cout << "Brain: overloaded copy constructor called" << std::endl;
    *this = brain;
}

Brain::~Brain()
{
    std::cout << "Brain: overloaded destructor called" << std::endl;
}

//operator(s) overload
Brain &Brain::operator=(const Brain &brain)
{
    std::cout << "Brain: overloaded assignment operator called" << std::endl;
    if (this == &brain) return *this;

    for(int count = 0; count < Brain::IDEAS_NUMBER; count++)
    {
        this->ideas[count] = brain.ideas[count];
    }
    return *this;
}

std::string Brain::getIdea(unsigned int index)
{
    return ideas[index];
}

void        Brain::setIdea(unsigned int index, const std::string &newIdeia)
{
    this->ideas[index] = newIdeia;
}
