#include "Array.hpp"

#include <iostream>

#define ARRAY_STRING_SIZE 3
#define ARRAY_INT_SIZE 5

void printArray(Array<int> &array)
{
    for(unsigned int count = 0; count < ARRAY_INT_SIZE; count++)
    {
        std::cout << array[count];
        if (ARRAY_INT_SIZE - count > 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

void printArray(Array<std::string> &array)
{
    for(unsigned int count = 0; count < ARRAY_STRING_SIZE; count++)
    {
        std::cout << array[count];
        if (ARRAY_STRING_SIZE - count > 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

int main(void)
{
    {
        std::cout << " +++++++++++++++++++++++++ INT +++++++++++++++++++++++++" << std::endl;
        Array<int> default_constructor;
        Array<int> array(ARRAY_INT_SIZE);
        for(unsigned int count = 0; count < ARRAY_INT_SIZE; count++)
            array[count] = count + 2;
        //print array
        std::cout << "the array     : ";
        printArray(array);
        Array<int> copyArray(array);
        std::cout << "the copy array: ";
        printArray(copyArray);
        std::cout << "changing the value in index 3 (copyArray)." << std::endl;
        try
        {
            copyArray[3] = 10;
        }
        catch(const std::exception &ex)
        {
            std::cout << "\tError: " << ex.what();
        }
        std::cout << "the copyArray : ";
        printArray(copyArray);
        std::cout << "the array     : ";
        printArray(array);
        std::cout << "trying to access a invalid index" << std::endl;
        try
        {
            array[42] = 10;
        }
        catch(const std::exception &ex)
        {
            std::cout << "\tError: " << ex.what() << std::endl;
        }
        std::cout << "\n" << std::endl;
    }

    {
        std::cout << " +++++++++++++++++++++++++ STRING +++++++++++++++++++++++++" << std::endl;
        Array<std::string> default_constructor;
        Array<std::string> array(ARRAY_STRING_SIZE);
        //print array
        array[0] = "I";
        array[1] = "am";
        array[2] = "Marvin!";
        std::cout << "the array     : ";
        printArray(array);
        Array<std::string> copyArray(array);
        std::cout << "the copy array: ";
        printArray(copyArray);
        std::cout << "changing the values of indexes 0 and 1 (copyArray)." << std::endl;
        try
        {
            copyArray[0] = "You";
            copyArray[1] = "are";
        }
        catch(const std::exception &ex)
        {
            std::cout << "\tError: " << ex.what();
        }
        std::cout << "the copyArray : ";
        printArray(copyArray);
        std::cout << "the array     : ";
        printArray(array);
        std::cout << "trying to access a invalid index" << std::endl;
        try
        {
            array[42] = 10;
        }
        catch(const std::exception &ex)
        {
            std::cout << "\tError: " << ex.what() << std::endl;
        }
        std::cout << "\n" << std::endl;
    }
    return 0;
}
