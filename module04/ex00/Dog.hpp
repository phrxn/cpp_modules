#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

#include <string>

class Dog : public Animal
{
    // --- constructor(s) and destructor ---
    public:
        Dog(void);
        Dog(const Dog &dog);
        ~Dog();

    // --- functions ---
    public:
        //operator(s) overload
        Dog &operator=(const Dog &dog);

        //others
        void makeSound(void) const;
};

#endif
