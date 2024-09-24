#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <iostream>

#define COLOR_RESET "\033[0m"
#define COLOR_RED   "\033[91m"
#define COLOR_GREEN "\033[92m"
#define COLOR_MAGENTA  "\033[95m"
#define COLOR_CYAN  "\033[96m"



Base *generate(void)
{
    std::srand(static_cast<unsigned int>(time(0)));

    int number = std::rand() % 3; 

    switch(number)
    {
        case 0:
        {
            std::cout << "create a new pointer: " << COLOR_CYAN "A" COLOR_RESET << std::endl;
            return new A();
        }
        case 1:
        {
            std::cout << "create a new pointer: " << COLOR_CYAN "B" COLOR_RESET << std::endl;
            return new B();
        }
        case 2:
        {
            std::cout << "create a new pointer: " << COLOR_CYAN "C" COLOR_RESET << std::endl;
            return new C();
        }
    }
    return 0;
}

void    identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "pointer type: " << COLOR_GREEN "A" COLOR_RESET << std::endl; 
    if (dynamic_cast<B *>(p))
        std::cout << "pointer type: " << COLOR_GREEN "B" COLOR_RESET << std::endl; 
    if (dynamic_cast<C *>(p))
        std::cout << "pointer type: " << COLOR_GREEN "C" COLOR_RESET << std::endl; 
}

void    identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "reference type: " << COLOR_GREEN "A" COLOR_RESET << std::endl; 
    }
    catch(const std::exception &ex){};
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "reference type: " << COLOR_GREEN "B" COLOR_RESET << std::endl; 
    }
    catch(const std::exception &ex){};
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "reference type: " << COLOR_GREEN "C" COLOR_RESET << std::endl; 
    }
    catch(const std::exception &ex){};
}


int main(void)
{
    Base *b = generate();

    identify(b);
    identify(*b);

    delete b;

    return 0;
}
