#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal
{
    // --- variable(s) ---
    protected:
        std::string type;

    // --- constructor(s) and destructor ---
    public:
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal &wrongAnimal);
        virtual ~WrongAnimal();

    // --- functions ---
    public:
        //operator(s) overload
        WrongAnimal &operator=(const WrongAnimal &wrongAnimal);

        //getter(s)
        std::string getType(void) const;

        //others
        void makeSound(void) const;
};

#endif
