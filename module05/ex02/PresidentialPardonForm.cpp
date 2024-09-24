#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

// --- constructor(s) and destructor ---

//private constructor
PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("PresidentialPardonForm", MIN_GRADE_TO_SIGN, MIN_GRADE_TO_EXEC),
    target("--")
{
    std::cout << "PresidentialPardonForm: overloaded default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", MIN_GRADE_TO_SIGN, MIN_GRADE_TO_EXEC) ,
    target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form)
    : AForm(form),
    target(form.target)
{
    std::cout << "PresidentialPardonForm: overloaded copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm: overloaded destructor called" << std::endl;
}

//operator(s) overload
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &rhs)
{
    (void) rhs;

    std::cout << "PresidentialPardonForm: overloaded assignment operator called" << std::endl;
    return (*this);
}

//others
void        PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    beforeExecute(executor);
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string PresidentialPardonForm::getTarget(void) const
{
    return (this->target);
}

