#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

#include <string>

class WrongCat : public WrongAnimal 
{
    // --- constructor(s) and destructor ---
    public:
        WrongCat(void);
        WrongCat(const WrongCat &cat);
        ~WrongCat();

    // --- functions ---
    public:
        //operator(s) overload
        WrongCat &operator=(const WrongCat &cat);

        //others
        void makeSound(void) const;
};

#endif
