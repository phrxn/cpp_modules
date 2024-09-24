#include "easyfind.hpp"

#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>

int main(void)
{
    {
        std::vector<int> v1;
        std::cout << "container before adding the items" << std::endl;
        printAContainer("vector", v1);
        for (unsigned int count = 1; count <= 10; ++count)
        {
            v1.push_back(count);
        }
        std::cout << "container after adding the items" << std::endl;
        printAContainer("vector", v1);

        std::cout << std::endl;

        std::cout << "trying to find the a item... (valid) the int 3" << std::endl;
        try
        {
            std::vector<int>::const_iterator result = easyfind(v1, 3);
            std::cout << "\tValue found with easyfind: " << *result << std::endl;
        }
        catch(const std::exception &ex)
        {
            std::cout << "\tError: " << ex.what() << std::endl;
        }

        std::cout << "trying to find the a item... (invalid) the int 42" << std::endl;
        try
        {
            std::vector<int>::const_iterator result = easyfind(v1, 42);
            std::cout << "\tvalue found with easyfind: " << *result << std::endl;
        }
        catch(const std::exception &ex)
        {
            std::cout << "\tError: " << ex.what() << std::endl;
        }
    }

    std::cout << "=============\n" << std::endl;


    {
        std::list<int> v1;
        std::cout << "container before adding the items" << std::endl;
        printAContainer("list", v1);
        for (unsigned int count = 1; count <= 10; ++count)
        {
            v1.push_back(count);
        }
        std::cout << "container after adding the items" << std::endl;
        printAContainer("list", v1);

        std::cout << std::endl;

        std::cout << "trying to find the a item... (valid) the int 3" << std::endl;
        try
        {
            std::list<int>::const_iterator result = easyfind(v1, 3);
            std::cout << "\tValue found with easyfind: " << *result << std::endl;
        }
        catch(const std::exception &ex)
        {
            std::cout << "\tError: " << ex.what() << std::endl;
        }

        std::cout << "trying to find the a item... (invalid) the int 42" << std::endl;
        try
        {
            std::list<int>::const_iterator result = easyfind(v1, 42);
            std::cout << "\tvalue found with easyfind: " << *result << std::endl;
        }
        catch(const std::exception &ex)
        {
            std::cout << "\tError: " << ex.what() << std::endl;
        }
    }

}
