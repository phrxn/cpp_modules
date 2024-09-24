#include "whatever.hpp"

#include <iostream>
#include <string>

int main(void)
{
    int a = 2;
    int b = 3;

    std::cout << "before swap: a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "after swap : a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    
    std::cout << "======" << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    std::cout << "before swap: c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "after swap : a = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

    std::cout << "======" << std::endl;

    const int a2 = 2;
    const int b2 = 3;

    std::cout << "a2 = " << a2 << ", b2 = " << b2 << std::endl;
    std::cout << "min( a2, b2 ) = " << ::min(a2, b2) << std::endl;
    std::cout << "max( a2, b2 ) = " << ::max(a2, b2) << std::endl;

    const std::string c2 = "chaine1";
    const std::string d2 = "chaine2";

    std::cout << "c2 = " << c2 << ", d2 = " << d2 << std::endl;
    std::cout << "min( c2, d2 ) = " << ::min(c2, d2) << std::endl;
    std::cout << "max( c2, d2 ) = " << ::max(c2, d2) << std::endl;

    return 0;
}
