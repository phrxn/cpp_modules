#include "ScalarConverter.hpp"

#include <iostream>

#define COLOR_RESET "\033[0m"
#define COLOR_RED   "\033[91m"
#define COLOR_GREEN "\033[92m"
#define COLOR_MAGENTA  "\033[95m"
#define COLOR_CYAN  "\033[96m"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./converter <the string scalar>\n"
        "Converts a valid scalar string to (char, int, float and double)\n"
        << std::endl;
        return (1);
    }

    try
    {
        ScalarConverter::convert(argv[1]);
    }
    catch(const std::exception &ex)
    {
        std::cout << COLOR_RED "Error: " COLOR_RESET <<
                  ex.what() << COLOR_RESET << std::endl;
        return (1);
    }
    return (0);
}
