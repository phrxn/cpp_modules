#include "iter.hpp"

#include <iostream>
#include <string>


int main(void)
{
    {
          int a1[3] = {2,3,4};
          std::cout << " ++++++++++ array of int ++++++++++ " << std::endl;
          printArray(a1, 3);
          std::cout << " ==== increment ====" << std::endl;
          ::iter(a1, 3, increment<int>);
          printArray(a1, 3);
          std::cout << " ==== decrement ====" << std::endl;
          iter(a1, 3, decrement<int>);
          printArray(a1, 3);
    }
    std::cout << "\n" << std::endl;
    {
          char a1[3] = {'a', 'b', 'c'};
          std::cout << " ++++++++++ array of char ++++++++++ " << std::endl;
          printArray(a1, 3);
          std::cout << " ==== increment ====" << std::endl;
          iter(a1, 3, increment<char>);
          printArray(a1, 3);
          std::cout << " ==== decrement ====" << std::endl;
          iter(a1, 3, decrement<char>);
          printArray(a1, 3);
    }

    return (0);
}
