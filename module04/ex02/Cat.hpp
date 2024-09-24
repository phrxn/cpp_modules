#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

#include <string>

class Cat : public AAnimal 
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
