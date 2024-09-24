#include "Span.hpp"

#define COLOR_RESET "\033[0m"
#define COLOR_RED   "\033[91m"
#define COLOR_GREEN "\033[92m"
#define COLOR_MAGENTA  "\033[95m"
#define COLOR_CYAN  "\033[96m"

#include <algorithm>
#include <cstdlib>
#include <iostream>

void theTests(Span &spanToTest, unsigned int size)
{
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "\t\t\tSpan size: " << size << "\n";
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

    std::cout << "======= test addNumber(int) ======" << std::endl; 

    std::cout << "trying add the number 100..." << std::endl;
    try
    {
        spanToTest.addNumber(100);
        std::cout << COLOR_GREEN "number 100 added." COLOR_RESET << std::endl;
    }
    catch(const std::exception &ex)
    {
        std::cout << COLOR_RED "Error: unable to add number 100: " COLOR_RESET
                  << COLOR_MAGENTA << ex.what() << COLOR_RESET << std::endl;
    }
    std::cout << "trying other number (567)..." << std::endl;
    try
    {
        spanToTest.addNumber(567);
        std::cout << COLOR_GREEN "number 567 added." COLOR_RESET << std::endl;
    }
    catch(const std::exception &ex)
    {
        std::cout << COLOR_RED "Error: unable to add number 100: " COLOR_RESET
                  << COLOR_MAGENTA << ex.what() << COLOR_RESET << std::endl;
    }

    std::cout << "======= test addNumber(iterator begin, iterator end) ======" << std::endl; 

    std::cout << "trying add the empty list " << std::endl;
    std::list<int> listEmpty;
    try
    {
        spanToTest.addNumber(listEmpty.begin(), listEmpty.end());
        std::cout << COLOR_GREEN "trying to \"\"add\"\" an empty list passed the test." COLOR_RESET << std::endl;
    }
    catch(const std::exception &ex)
    {
        std::cout << COLOR_RED "Error: unable \"added\" a empty list: " COLOR_RESET
                  << COLOR_MAGENTA << ex.what() << COLOR_RESET << std::endl;
    }

    std::cout << "trying add the list {10000}..." << std::endl;
    std::list<int> listOneItem;
    listOneItem.push_back(10000);
    try
    {
        spanToTest.addNumber(listOneItem.begin(), listOneItem.end());
        std::cout << COLOR_GREEN "list {10000} added." COLOR_RESET << std::endl;
    }
    catch(const std::exception &ex)
    {
        std::cout << COLOR_RED "Error: unable to list {10000}: " COLOR_RESET
                  << COLOR_MAGENTA << ex.what() << COLOR_RESET << std::endl;
    }

    std::cout << "trying add the list {100000, -2000000000}..." << std::endl;
    std::list<int> listTwoItems;
    listTwoItems.push_back(100000);
    listTwoItems.push_back(-2000000000);
    try
    {
        spanToTest.addNumber(listTwoItems.begin(), listTwoItems.end());
        std::cout << COLOR_GREEN "list {100000, -2000000000} added." COLOR_RESET << std::endl;
    }
    catch(const std::exception &ex)
    {
        std::cout << COLOR_RED "Error: unable to list {1000000, -2000000000}: " COLOR_RESET
                  << COLOR_MAGENTA << ex.what() << COLOR_RESET << std::endl;
    }
    std::cout << "======= test logestSpan(void) ======" << std::endl; 
    try
    {
        unsigned int longest = spanToTest.longestSpan();
        std::cout << "longest = " << longest << std::endl;
    }
    catch(const std::exception &ex)
    {
        std::cout << COLOR_RED "Error: unable to get longestSpan: " COLOR_RESET
                  << COLOR_MAGENTA << ex.what() << COLOR_RESET << std::endl;
    }
    std::cout << "======= test shortestSpan(void) ======" << std::endl; 
    try
    {
        unsigned int shortest = spanToTest.shortestSpan();
        std::cout << "shortest = " << shortest << std::endl;
    }
    catch(const std::exception &ex)
    {
        std::cout << COLOR_RED "Error: unable to get shortestSpan: " COLOR_RESET
                  << COLOR_MAGENTA << ex.what() << COLOR_RESET << std::endl;
    }
    std::cout << "\n\n" << std::endl;
}

void theSubjectExample()
{
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "\t\t\tThe subject test: " << "\n";
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "\n\n" << std::endl;
}

void bigTest()
{
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "\t\t\t Big test: " << "\n";
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

    try
    {
        std::list<int> listRandomInts(50000);
        std::srand(time(NULL));
        std::generate(listRandomInts.begin(), listRandomInts.end(), std::rand);

        Span span(listRandomInts.size());

        span.addNumber(listRandomInts.begin(), listRandomInts.end());

        std::cout << "longest: " << span.longestSpan() << std::endl;
        std::cout << "shortest: " << span.shortestSpan() << std::endl;

        std::cout << "======== copy test ========" << std::endl;
        Span spanCopy(span);
        std::cout << "longest: " << spanCopy.longestSpan() << std::endl;
        std::cout << "shortest: " << spanCopy.shortestSpan() << std::endl;
        std::cout << "======== assignment test ========" << std::endl;
        Span spanAssignment(0);
        spanAssignment = span;
        std::cout << "longest: " << spanAssignment.longestSpan() << std::endl;
        std::cout << "shortest: " << spanAssignment.shortestSpan() << std::endl;
        
    }
    catch (const std::exception& e )
    {
        std::cout << COLOR_RED "Error: " COLOR_RESET << e.what() << std::endl; 
    }


    std::cout << "\n\n" << std::endl;
}

int main(void)
{
    //private constructor
    //Span privateConstructor;
    
    theSubjectExample();
    
    Span span1(1);
    theTests(span1, 1);

    Span span2(2);
    theTests(span2, 2);

    Span span3(3);
    theTests(span3, 3);

    Span span4(4);
    theTests(span4, 4);

    Span span5(5);
    theTests(span5, 5);

    bigTest();

    return 0;
}
