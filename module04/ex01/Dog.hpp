#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#include <string>

class Dog : public Animal
{
    // --- variable(s) ---
    private:
        Brain *brain;

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

        Brain &getBrain(void);
};

#endif
