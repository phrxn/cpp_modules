#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

#include <string>

class Dog : public AAnimal
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
