#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
    // --- variable(s) ---
    protected:
        std::string type;

    // --- constructor(s) and destructor ---
    public:
        Animal(void);
        Animal(const Animal &animal);
        virtual ~Animal();

    // --- functions ---
    public:
        //operator(s) overload
        Animal &operator=(const Animal &animal);

        //getter(s)
        std::string getType(void) const;

        //others
        virtual void makeSound(void) const;
};

#endif
