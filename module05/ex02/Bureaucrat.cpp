#include "Bureaucrat.hpp"

#include <iostream>
#include <string>
#include <sstream>

#define COLOR_RESET "\033[0m"
#define COLOR_RED   "\033[91m"
#define COLOR_GREEN "\033[92m"
#define COLOR_MAGENTA  "\033[95m"
#define COLOR_CYAN  "\033[96m"

// --- constructors ---
//private constructor...
Bureaucrat::Bureaucrat(void): name("--")
{
#ifdef DEBUG
    std::cout << "Bureaucrat: overloaded default constructor called" << std::endl;
#endif
    this->grade = -1;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) :
    name(bureaucrat.name)
{
#ifdef DEBUG
    std::cout << "Bureaucrat: overloaded copy constructor called" << std::endl;
#endif
    *this = bureaucrat;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) 
    throw(Bureaucrat::GradeTooLowException, Bureaucrat::GradeTooHighException) :
    name(name), grade(grade)
{
#ifdef DEBUG
    std::cout << "Bureaucrat: name and grade constructor called" << std::endl;
#endif
    isGradeValid(grade);
}

Bureaucrat::~Bureaucrat(void)
{
#ifdef DEBUG
    std::cout << "Bureaucrat: overloaded destructor called" << std::endl;
#endif
}

// --- functions ---

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
#ifdef DEBUG
    std::cout << "Bureaucrat: overloaded assignment operator called" << std::endl;
#endif

    //if the object to assign is the object itself, just return the object.
    if (this == &bureaucrat) return *this;

    this->grade = bureaucrat.grade;

    return (*this);
}

//getter(s)
std::string const   &Bureaucrat::getName(void) const
{
    return (this->name);
}

int                 Bureaucrat::getGrade(void) const
{
    return (this->grade);
}

//others
void Bureaucrat::incrementGrade(void)
    throw(Bureaucrat::GradeTooLowException, Bureaucrat::GradeTooHighException)
{
    isGradeValid(this->grade - 1);
    this->grade--;
    std::cout << "The bureaucrat [" << this->name << "] was promoved to grade: " << this->grade << std::endl;
}

void Bureaucrat::decrementGrade(void)
    throw(Bureaucrat::GradeTooLowException, Bureaucrat::GradeTooHighException)
{
    isGradeValid(this->grade + 1);
    this->grade++;
    std::cout << "The bureaucrat [" << this->name << "] was demoted to grade: " << this->grade << std::endl;
}

void Bureaucrat::signForm(AForm &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << COLOR_GREEN "Successfully! " COLOR_RESET
        COLOR_CYAN << this->name << COLOR_RESET
        " signed the form: "
        COLOR_CYAN << form.getName() << COLOR_RESET <<
        std::endl;
    }
    catch(const std::exception &ex)
    {
        std::cout << COLOR_RED "Error: " COLOR_RESET
        COLOR_CYAN << this->name << COLOR_RESET
        " cannot sign the form: " 
        COLOR_MAGENTA << ex.what() << COLOR_RESET <<
        std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
        std::cout << COLOR_CYAN << *this << COLOR_RESET
                  " executed the " 
                  COLOR_CYAN << form << COLOR_RESET <<
                  std::endl;
    }
    catch(const std::exception &ex)
    {
        std::cout << COLOR_RED "Error: " COLOR_RESET
                  COLOR_CYAN << *this << COLOR_RESET
                  " couldn't executed the " 
                  COLOR_CYAN << form << COLOR_RESET
                  ": " <<
                  ex.what() << std::endl;
    }
}

void Bureaucrat::isGradeValid(int grade)
    throw(Bureaucrat::GradeTooLowException, Bureaucrat::GradeTooHighException)
{
    std::string strExMessage;

    if (grade < Bureaucrat::HIGH_POSSIBLE_GRADE)
    {
        std::stringstream ss;
        ss << Bureaucrat::HIGH_POSSIBLE_GRADE;
        strExMessage = "a bureaucrat cannot have a grade greater than ";
        strExMessage += ss.str();
        throw (Bureaucrat::GradeTooHighException(strExMessage));
    }
    if (grade > Bureaucrat::LOW_POSSIBLE_GRADE)
    {
        std::stringstream ss;
        ss << Bureaucrat::LOW_POSSIBLE_GRADE;
        strExMessage = "a bureaucrat cannot have a grade lower than ";
        strExMessage += ss.str();
        throw (Bureaucrat::GradeTooLowException(strExMessage));
    }
}

// ---------- nested class(es) ----------

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &strExMessage)
    : strExMessage(strExMessage){};
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw (){};
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return (strExMessage.c_str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &strExMessage)
    : strExMessage(strExMessage){};
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw (){};
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return (strExMessage.c_str());
}


// --- 
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << "Bureaucrat name:[" << bureaucrat.getName() <<
          "], grade:[" << bureaucrat.getGrade() << "]";
    return os;
}
