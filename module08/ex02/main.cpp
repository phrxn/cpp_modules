#include "MutantStack.hpp"

#include <iostream>
#include <string>

#define COLOR_RESET "\033[0m"
#define COLOR_RED   "\033[91m"
#define COLOR_GREEN "\033[92m"
#define COLOR_MAGENTA  "\033[95m"
#define COLOR_CYAN  "\033[96m"

template <typename T>
void printMutantStack(MutantStack<T> &mutant)
{
    if (mutant.size() == 0)
        return ;

    typename MutantStack<T>::iterator it  = mutant.begin();
    typename MutantStack<T>::iterator ite = mutant.end();
    while (it != ite)
    {
        std::cout << *it;
        ++it;
        if (it != ite)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

template <typename T>
void testAllIters(MutantStack<T> &mutant)
{
    if (mutant.size() == 0)
    {
        std::cout << "The mutantStack is empty!" << std::endl;
        return ;
    }

    {
        std::cout << "the stack (iterator):" << std::endl;
        std::cout << "---------------- TOP ----------------" << std::endl;

        typename MutantStack<T>::iterator it  = mutant.begin();
        typename MutantStack<T>::iterator ite = mutant.end();
        while(it != ite)
        {
            std::cout << "|    " << *it << "    |" << std::endl;
            ++it;
        }
        std::cout << "---------------- BOTTOM ----------------\n" << std::endl;
    }
    {
        std::cout << "the stack (const iterator):" << std::endl;
        std::cout << "---------------- TOP ----------------" << std::endl;

        typename MutantStack<T>::const_iterator it  = mutant.begin();
        typename MutantStack<T>::const_iterator ite = mutant.end();
        while(it != ite)
        {
            std::cout << "|    " << *it << "    |" << std::endl;
            ++it;
        }
        std::cout << "---------------- BOTTOM ----------------\n" << std::endl;
    }
    {
        std::cout << "the stack (reverse iterator):" << std::endl;
        std::cout << "---------------- BOTTOM ----------------" << std::endl;

        typename MutantStack<T>::reverse_iterator it  = mutant.rbegin();
        typename MutantStack<T>::reverse_iterator ite = mutant.rend();
        while(it != ite)
        {
            std::cout << "|    " << *it << "    |" << std::endl;
            ++it;
        }
        std::cout << "---------------- TOP ----------------\n" << std::endl;
    }

    {
        std::cout << "the stack (const reverse iterator):" << std::endl;
        std::cout << "---------------- BOTTOM ----------------" << std::endl;

        typename MutantStack<T>::const_reverse_iterator it  = mutant.rbegin();
        typename MutantStack<T>::const_reverse_iterator ite = mutant.rend();
        while(it != ite)
        {
            std::cout << "|    " << *it << "    |" << std::endl;
            ++it;
        }
        std::cout << "---------------- TOP ----------------\n" << std::endl;
    }


/*    {
        std::cout << "------- TOP -------" << std::endl;
        std::cout << "|    " << mutant.
    }
*/

}



void subjectTest()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Is top 17: " <<  mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Is size 17: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}


void test1()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Is top 17: " <<  mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Is size 17: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}


void basicTest()
{
    MutantStack<int> mutantStack;
    mutantStack.push(1);
    mutantStack.push(2);
    mutantStack.push(3);

    std::cout << "the mutantStack:" << std::endl;
    printMutantStack(mutantStack);

    std::cout << "copy test:" << std::endl;
    MutantStack<int> copy(mutantStack);
    printMutantStack(copy);

    std::cout << "assigment (initialization) test:" << std::endl;
    MutantStack<int> assignment(mutantStack);
    printMutantStack(assignment);

    std::cout << "assigment test:" << std::endl;
    MutantStack<int> assignment2 = assignment;
    printMutantStack(assignment2);
}

int main(void)
{
//    std::cout << "----------------------------------------------" << std::endl;
    //subjectTest();

    {
        std::cout << "----------------------------------------------" << std::endl;
        std::cout << COLOR_GREEN "\t\tMutantStack<int>          " COLOR_RESET << std::endl;
        std::cout << "----------------------------------------------" << std::endl;
        MutantStack<int> mutantStack;
        mutantStack.push(1);
        mutantStack.push(2);
        mutantStack.push(3);
        testAllIters(mutantStack);
    }
    {
        std::cout << "----------------------------------------------" << std::endl;
        std::cout << COLOR_GREEN "\t\tMutantStack<string>          " COLOR_RESET << std::endl;
        std::cout << "----------------------------------------------" << std::endl;
        MutantStack<std::string> mutantStack;
        mutantStack.push("I");
        mutantStack.push("am");
        mutantStack.push("Marvin!");
        testAllIters(mutantStack);
    }

    std::cout << "----------------------------------------------" << std::endl;
    std::cout << COLOR_MAGENTA "\t\tBasic tests          " COLOR_RESET << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    basicTest();

    std::cout << "----------------------------------------------" << std::endl;
    std::cout << COLOR_MAGENTA "\t\tSubject test          " COLOR_RESET << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    subjectTest();

    return 0;
}
