#include "Bureaucrat.hpp"

#include <iostream>
#include <string>
#include <sstream>

// --- constructors ---
//private constructor...
Bureaucrat::Bureaucrat(void): name("--")
{
    std::cout << "Bureaucrat: overloaded default constructor called" << std::endl;
    this->grade = -1;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) :
    name(bureaucrat.name)
{
    std::cout << "Bureaucrat: overloaded copy constructor called" << std::endl;
    *this = bureaucrat;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) 
    throw(Bureaucrat::GradeTooLowException, Bureaucrat::GradeTooHighException) :
    name(name), grade(grade)
{
    std::cout << "Bureaucrat: name and grade constructor called" << std::endl;
    isGradeValid(grade);
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat: overloaded destructor called" << std::endl;
}

// --- functions ---

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
    std::cout << "Bureaucrat: overloaded assignment operator called" << std::endl;

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
