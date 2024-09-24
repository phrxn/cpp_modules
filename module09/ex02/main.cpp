#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>

#include "PmergeMe.hpp"

void showHelp()
{
    std::cout << "Usage: ./PmergeMe <number list to sort>" << std::endl;
    std::cout << "The numbers MUST BE positive, integers and not duplicated."
              << std::endl;
}

bool isParametersValid(const int argc, const char *const *argv)
{
    if (argc < 2)
    {
        showHelp();
        return false;
    }

    // check if all parameters are positive integer numbers
    for (int countNumbers = 1; countNumbers < argc; ++countNumbers)
    {
        char *stringRest;
        long longNumber = strtol(argv[countNumbers], &stringRest, 10);
        bool isParamenterInvalid = false;
        if (stringRest[0] != '\0')
            isParamenterInvalid = true;
        else if (longNumber < 1 || longNumber > std::numeric_limits<int>::max())
            isParamenterInvalid = true;
        if (isParamenterInvalid)
        {
            std::cout << "The parameter: " << argv[countNumbers]
                      << " is invalid." << std::endl;
            showHelp();
            return false;
        }
    }

    // check if there is a duplicate number
    for (int countMain = 1; countMain < argc; ++countMain)
    {
        for (int countToCompare = countMain + 1; countToCompare < argc;
             ++countToCompare)
        {
            if (std::string(argv[countMain]) ==
                std::string(argv[countToCompare]))
            {
                std::cout << "The parameter: " << argv[countMain]
                          << " is duplicated." << std::endl;
                showHelp();
                return false;
            }
        }
    }
    return true;
}

void printTime(const clock_t timeToPrint)
{
    std::cout << static_cast<double>(timeToPrint) / CLOCKS_PER_SEC * 1000
              << std::flush;
}

int main(int argc, char **argv)
{
    if (!isParametersValid(argc, argv))
        return 1;
    if (argc == 2)
    {
        std::cout << argv[1] << std::endl;
        return 0;
    }

    std::cout << "Before: ";
    for (int countArgs = 1; countArgs < argc; ++countArgs)
    {
        std::cout << argv[countArgs];
        if (countArgs + 1 < argc)
            std::cout << " ";
    }
    std::cout << std::endl;

    clock_t timeToList = clock();
    PmergeMe::PmergeMeList pmergeMeList;
    pmergeMeList.sort(argv);
    timeToList = clock() - timeToList;

    clock_t timeToVector = clock();
    PmergeMe::PmergeMeVector pmergeMeVector;
    pmergeMeVector.sort(argv);
    timeToVector = clock() - timeToVector;

    std::cout << "After: ";
    std::list<int>::const_iterator itCount =
        pmergeMeList.getMainChain().begin();
    while (itCount != pmergeMeList.getMainChain().end())
    {
        std::cout << *itCount << " ";
        ++itCount;
    }
    std::cout << std::endl;

    // list
    std::cout << "Time to process a range of " << (argc - 1)
              << " elements with std::list : ";
    printTime(timeToList);
    std::cout << " ms" << std::endl;

    // vector
    std::cout << "Time to process a range of " << (argc - 1)
              << " elements with std::vector : ";
    printTime(timeToVector);
    std::cout << " ms" << std::endl;
    return 0;
}
