#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#include <string>

class Cat : public Animal 
{
    // --- variable(s) ---
    private:
        Brain *brain;

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

        //functions;
        Brain &getBrain(void);
};

#endif
