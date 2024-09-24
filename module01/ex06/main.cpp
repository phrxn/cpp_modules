#include "Harl.hpp"

#include <iostream>

int main(int argc, char **argv)
{
    Harl        harl;

    if (argc != 2)
    {
        std::cout << "Usage: harlFilter <level>" << std::endl;
        return 1;
    }
    std::string input = argv[1];

    harl.complain(input);

    return 0;
}
