#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class AAnimal
{
    // --- variable(s) ---
    protected:
        std::string type;

    // --- constructor(s) and destructor ---
    public:
        AAnimal(void);
        AAnimal(const AAnimal &aanimal);
        virtual ~AAnimal();

    // --- functions ---
    public:
        //operator(s) overload
        AAnimal &operator=(const AAnimal &aanimal);

        //getter(s)
        std::string getType(void) const;

        //others
        virtual void makeSound(void) const = 0;
};

#endif
