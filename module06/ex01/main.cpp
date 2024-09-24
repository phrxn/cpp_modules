#include "Serializer.hpp"
#include "Data.hpp"

#include <stdint.h>
#include <iostream>

#define COLOR_RESET "\033[0m"
#define COLOR_RED   "\033[91m"
#define COLOR_GREEN "\033[92m"

int main(void)
{
    Data data = Data(42, "Hi!");
    uintptr_t uint;


    uint = Serializer::serialize(&data);
    Data *data2 = Serializer::deserialize(uint);

    if (&data == data2)
        std::cout << COLOR_GREEN "Ok: " COLOR_RESET "convert" COLOR_RESET << std::endl;
    else
        std::cout << COLOR_RED "Error! " COLOR_RESET "convert" COLOR_RESET << std::endl;

    return 0;
}
