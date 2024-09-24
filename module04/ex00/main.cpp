#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main(void)
{

    std::cout << "\n             *** generic animal ***" << std::endl;
    Animal *animalGeneric = new Animal();
    std::cout << "\tType     : " << animalGeneric->getType() << std::endl;
    std::cout << "\tIts sound: "; animalGeneric->makeSound();
    delete animalGeneric;
    std::cout << std::endl;

    std::cout << "               *** animal dog ***" << std::endl;
    const Animal *animalDog = new Dog(); 
    std::cout << "\tType     : " << animalDog->getType() << std::endl;
    std::cout << "\tIts sound: "; animalDog->makeSound();
    delete animalDog;
    std::cout << std::endl;

    std::cout << "               *** animal cat ***" << std::endl;
    const Animal *animalCat = new Cat(); 
    std::cout << "\tType     : " << animalCat->getType() << std::endl;
    std::cout << "\tIts sound: "; animalCat->makeSound();
    delete animalCat;
    std::cout << std::endl;

    std::cout << "               *** pure dog ***" << std::endl;
    const Dog *dogDog = new Dog(); 
    std::cout << "\tType     : " << dogDog->getType() << std::endl;
    std::cout << "\tIts sound: "; dogDog->makeSound();
    delete dogDog;
    std::cout << std::endl;

    std::cout << "               *** pure cat ***" << std::endl;
    const Cat *catCat = new Cat(); 
    std::cout << "\tType     : " << catCat->getType() << std::endl;
    std::cout << "\tIts sound: "; catCat->makeSound();
    delete catCat;
    std::cout << std::endl;

    std::cout << "               *** wrong animal ***" << std::endl;
    const WrongAnimal *wrongAnimal = new WrongAnimal(); 
    std::cout << "\tType     : " << wrongAnimal->getType() << std::endl;
    std::cout << "\tIts sound: "; wrongAnimal->makeSound();
    delete wrongAnimal;
    std::cout << std::endl;

    std::cout << "               *** wrong cat ***" << std::endl;
    const WrongAnimal *wrongCat = new WrongCat(); 
    std::cout << "\tType     : " << wrongCat->getType() << std::endl;
    std::cout << "\tIts sound: "; wrongCat->makeSound();
    delete wrongCat;
    std::cout << std::endl;
    return 0;
}

