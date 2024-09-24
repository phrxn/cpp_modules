#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define COLOR_RESET "\033[0m"
#define COLOR_RED   "\033[91m"
#define COLOR_GREEN "\033[92m"
#define COLOR_MAGENTA  "\033[95m"
#define COLOR_CYAN  "\033[96m"

Intern::Intern(void)
{
    std::cout << "Intern: overloaded default constructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
    (void)src;
    std::cout << "Intern: overloaded copy constructor called" << std::endl;
}

Intern:: ~Intern(void)
{
    std::cout << "Intern: overloaded copy constructor called" << std::endl;
}

//operator(s) overload
Intern &Intern::operator=(const Intern &rhs)
{
    std::cout << "Intern: overloaded assignment operator called" << std::endl;
    (void) rhs;
    return *this;
}

//others
AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
    AForm           *theForm = 0;
    unsigned int    index = 0;


    std::string formNames[] =
    {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };
    
    for(int count = 0; count < 3; ++count)
    {
        if (name == formNames[count])
            break ;
        index++;
    }
    
    switch(index)
    {
        case 0:
            theForm = new PresidentialPardonForm(target);
            break;
        case 1:
            theForm = new RobotomyRequestForm(target);
            break;
        case 2:
            theForm = new ShrubberyCreationForm(target);
    }

    //alloc fatal error! the (new) may fail!
    if (index < 3 && theForm == 0)
    {
        std::cout << COLOR_RED "Fatal! " COLOR_RESET
        " unable to allocate the form: "
        COLOR_CYAN << name << COLOR_RESET <<
        std::endl;
        return (0);
    }

    // the form name don't found.
    if (!theForm)
    {
        std::cout << COLOR_RED "Erro! " COLOR_RESET
            "The form: " 
            COLOR_CYAN << name << COLOR_RESET
            " doesn't exist!" <<
            std::endl;
        return (0);
    }

    return (theForm);
}
