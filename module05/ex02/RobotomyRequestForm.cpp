#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstdlib>

#define COLOR_RESET "\033[0m"
#define COLOR_RED   "\033[91m"
#define COLOR_GREEN "\033[92m"
#define COLOR_MAGENTA  "\033[95m"
#define COLOR_CYAN  "\033[96m"



// --- constructor(s) and destructor ---

//private constructor
RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("RobotomyRequestForm", MIN_GRADE_TO_SIGN, MIN_GRADE_TO_EXEC),
    target("--")
{
    std::cout << "RobotomyRequestForm: overloaded default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", MIN_GRADE_TO_SIGN, MIN_GRADE_TO_EXEC) ,
    target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form)
    : AForm(form),
    target(form.target)
{
    std::cout << "RobotomyRequestForm: overloaded copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm: overloaded destructor called" << std::endl;
}

//operator(s) overload
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &rhs)
{
    (void) rhs;

    std::cout << "RobotomyRequestForm: overloaded assignment operator called" << std::endl;
    return (*this);
}

//others
void        RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    beforeExecute(executor);
    std::srand(static_cast<unsigned int>(time(0)));
    std::cout << "... vrmmm... vrm... pi... pi... ..." << std::endl;
    if (std::rand() % 2 == 0)
    {
        std::cout << COLOR_GREEN "successfully! " COLOR_RESET <<
                  this->target <<
                  " robotomized! " <<
                  std::endl;
    }
    else
    {
        std::cout << COLOR_RED "failed! " COLOR_RESET <<
                  this->target <<
                  " wasn't robotomized! " <<
                  std::endl;
    }
}

std::string RobotomyRequestForm::getTarget(void) const
{
    return (this->target);
}


