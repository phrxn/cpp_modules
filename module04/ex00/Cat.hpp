#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

#include <string>

class Cat : public Animal 
{
    // --- constructor(s) and destructor ---
    public:
        Cat(void);
        Cat(const Cat &cat);
        ~Cat();

    // --- functions ---
    public:
        //operator(s) overload
        Cat &operator=(const Cat &cat);

        //others
        void makeSound(void) const;
};

#endif
