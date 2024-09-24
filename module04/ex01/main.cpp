#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>

#define STATIC_ARRAY_ANIMAL_SIZE 4

int main(void)
{
    //simple teste;
    std::cout << "               ***simple test***" << std::endl;
    const Animal* j = new Dog();
    std::cout << "---" << std::endl;
    const Animal* i = new Cat();
    std::cout << "\n" << std::endl;
    delete j;//should not create a leak
    std::cout << "---" << std::endl;
    delete i;
    std::cout << "\n" << std::endl;

    //array animals
    std::cout << "               ***static array test***" << std::endl;
    Animal *arrayAnimalStatic[STATIC_ARRAY_ANIMAL_SIZE];
    for(int count = 0; count < STATIC_ARRAY_ANIMAL_SIZE/2; count++)
        arrayAnimalStatic[count] = new Cat();
    for(int count = STATIC_ARRAY_ANIMAL_SIZE/2; count < STATIC_ARRAY_ANIMAL_SIZE; count++)
        arrayAnimalStatic[count] = new Dog();
    std::cout << "---" << std::endl;
    std::cout << "arrayAnimalStatic[0] type == Cat? " << arrayAnimalStatic[0]->getType() << std::endl;
    std::cout << "arrayAnimalStatic[1] type == Cat? " << arrayAnimalStatic[1]->getType() << std::endl;
    std::cout << "arrayAnimalStatic[2] type == Dog? " << arrayAnimalStatic[2]->getType() << std::endl;
    std::cout << "arrayAnimalStatic[3] type == Dog? " << arrayAnimalStatic[3]->getType() << std::endl;
    std::cout << "---" << std::endl;
    for(int count = 0; count < STATIC_ARRAY_ANIMAL_SIZE; count++)
    {
        std::cout << "Make sound " << arrayAnimalStatic[count]->getType() << " ";
        arrayAnimalStatic[count]->makeSound();
    }
    for(int count = 0; count < STATIC_ARRAY_ANIMAL_SIZE; count++)
        delete arrayAnimalStatic[count];
    std::cout << "\n" << std::endl;

    //array animals
    std::cout << "               ***dinamic array test***" << std::endl;
    Animal **arrayAnimalDinamic = new Animal*[STATIC_ARRAY_ANIMAL_SIZE];
    for(int count = 0; count < STATIC_ARRAY_ANIMAL_SIZE/2; count++)
        arrayAnimalDinamic[count] = new Cat();
    for(int count = STATIC_ARRAY_ANIMAL_SIZE/2; count < STATIC_ARRAY_ANIMAL_SIZE; count++)
        arrayAnimalDinamic[count] = new Dog();
    std::cout << "---" << std::endl;
    std::cout << "arrayAnimalDinamic[0] type == Cat? " << arrayAnimalDinamic[0]->getType() << std::endl;
    std::cout << "arrayAnimalDinamic[1] type == Cat? " << arrayAnimalDinamic[1]->getType() << std::endl;
    std::cout << "arrayAnimalDinamic[2] type == Dog? " << arrayAnimalDinamic[2]->getType() << std::endl;
    std::cout << "arrayAnimalDinamic[3] type == Dog? " << arrayAnimalDinamic[3]->getType() << std::endl;
    std::cout << "---" << std::endl;
    for(int count = 0; count < STATIC_ARRAY_ANIMAL_SIZE; count++)
        delete arrayAnimalDinamic[count];
    std::cout << "\n" << std::endl;
    delete[] arrayAnimalDinamic;
    std::cout << "\n" << std::endl;

    std::cout << "               *** Brain copy test***" << std::endl;
    std::cout << "create a brain1" << std::endl;
    Brain brain1;
    brain1.setIdea(0, "create a time machine!");
    brain1.setIdea(5, "write a new music!");
    std::cout << "---" << std::endl;
    std::cout << "create a brain2 from brain1(by copy constructor)" << std::endl;
    Brain brain2(brain1);
    std::cout << "Are 5th are equals? " << (brain2.getIdea(5) == "write a new music!") << std::endl;
    std::cout << "---" << std::endl;
    std::cout << "assignment brain2 to brain3(by assingment)" << std::endl;
    Brain brain3;
    brain3 = brain2;
    std::cout << "Are 5th are equals? " << (brain3.getIdea(5) == "write a new music!") << std::endl;
    std::cout << "\n" << std::endl;

    std::cout << "               *** Cat copy test***" << std::endl;
    std::cout << ">>> create a cat1" << std::endl;
    Cat cat1;
    cat1.getBrain().setIdea(0, "I want to hunt a mouse");
    cat1.getBrain().setIdea(42, "Is this roof safe?");
    std::cout << "---" << std::endl;
    std::cout << ">>> create a cat2 from cat1(by copy constructor)" << std::endl;
    Cat cat2(cat1);
    std::cout << ">>> Are 42th are equals? " << (cat2.getBrain().getIdea(42) == "Is this roof safe?") << std::endl;
    std::cout << "---" << std::endl;
    std::cout << ">>> creating cat3 and assignment cat2 to it" << std::endl;
    Cat cat3;
    std::cout << ">>> assignment" << std::endl;
    cat3 = cat2;
    std::cout << ">>> Are 42th are equals? " << (cat3.getBrain().getIdea(42) == "Is this roof safe?") << std::endl;
    std::cout << "\n" << std::endl;


    std::cout << "               *** Dog copy test***" << std::endl;
    std::cout << ">>> create a cat1" << std::endl;
    Dog dog1;
    dog1.getBrain().setIdea(0, "I want to hunt a cat");
    dog1.getBrain().setIdea(98, "I'm going to slepp zZZzz");
    std::cout << "---" << std::endl;
    std::cout << ">>> create a dog2 from dog1(by copy constructor)" << std::endl;
    Dog dog2(dog1);
    std::cout << ">>> Are 42th are equals? " << (dog2.getBrain().getIdea(98) == "I'm going to slepp zZZzz") << std::endl;
    std::cout << "---" << std::endl;
    std::cout << ">>> creating dog3 and assignment dog2 to it" << std::endl;
    Dog dog3;
    std::cout << ">>> assignment" << std::endl;
    dog3 = dog2;
    std::cout << ">>> Are 42th are equals? " << (dog3.getBrain().getIdea(98) == "I'm going to slepp zZZzz") << std::endl;
    std::cout << "\n" << std::endl;






    std::cout << "\n\n\n               *** The destructors for static objects will be called below this message***" << std::endl;
    return 0;
}

