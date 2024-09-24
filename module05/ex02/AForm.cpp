#include "AForm.hpp"

#include <sstream>

AForm::AForm(void) :
    name ("--"),
    _isSigned(false),
    gradeRequiredToSign(1),
    gradeRequiredToExecute(1)
{
#ifdef DEBUG
    std::cout << "AForm:  overloaded default constructor called" << std::endl;
#endif
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    throw(AForm::GradeTooLowException, AForm::GradeTooHighException) :
        name(name),
        _isSigned(false),
        gradeRequiredToSign(gradeToSign),
        gradeRequiredToExecute(gradeToExecute)
{
#ifdef DEBUG
    std::cout << "AForm:  name, granToSign and gradeToExecute constructor called" << std::endl;
#endif
    isGradeToSignValid(gradeToSign);
    isGradeToExecutionValid(gradeToExecute);
}

AForm::AForm(const AForm &form) :
    name (form.name),
    gradeRequiredToSign(form.gradeRequiredToSign),
    gradeRequiredToExecute(form.gradeRequiredToExecute)
{
#ifdef DEBUG
    std::cout << "AForm:  overloaded copy constructor called" << std::endl;
#endif
    *this = form;
}

AForm::~AForm()
{
#ifdef DEBUG
    std::cout << "AForm:  overloaded destructor called" << std::endl;
#endif
}

AForm &AForm::operator=(const AForm &form)
{
#ifdef DEBUG
    std::cout << "AForm: overloaded assignment operator called" << std::endl;
#endif

    if (this == &form) return *this;

    this->_isSigned = form._isSigned;

    return *this;
}

std::string const   &AForm::getName(void) const
{
    return (this->name);
}
int                 AForm::getGradeRequiredToSign(void) const
{
    return (this->gradeRequiredToSign);
}
int                 AForm::getGradeRequiredToExecute(void) const
{
    return (this->gradeRequiredToExecute);
}
bool                AForm::isSigned(void) const
{
    return (this->_isSigned);
}

void                AForm::beSigned(const Bureaucrat &bureaucrat)
    throw(AForm::FormSignException, AForm::GradeTooLowException)
{
    if (_isSigned)
        throw (AForm::FormSignException("The form is already signed"));
    if(bureaucrat.getGrade() > this->gradeRequiredToSign)
        throw(AForm::GradeTooLowException("The bureaucrat's grade is smaller than necessary"));
    this->_isSigned = true;
}

void    AForm::beforeExecute(const Bureaucrat &bureaucrat) const
    throw (AForm::FormSignException, AForm::GradeTooLowException)
{
    if (!this->_isSigned)
        throw AForm::FormSignException("The form cannot be executed, it is not signing");
    if (bureaucrat.getGrade() > this->gradeRequiredToExecute)
        throw AForm::GradeTooLowException("The bureaucrat's grade is smaller than necessary to execute the form");
}

void    AForm::isGradeToSignValid(int grade)
    throw(AForm::GradeTooLowException, AForm::GradeTooHighException)
{
    std::string strExMessage;

    if (grade < Bureaucrat::HIGH_POSSIBLE_GRADE)
    {
        std::stringstream ss;
        ss << Bureaucrat::HIGH_POSSIBLE_GRADE;
        strExMessage = "the grade value to sign cannot be greater than ";
        strExMessage += ss.str();
        throw (AForm::GradeTooHighException(strExMessage));
    }
    if (grade > Bureaucrat::LOW_POSSIBLE_GRADE)
    {
        std::stringstream ss;
        ss << Bureaucrat::LOW_POSSIBLE_GRADE;
        strExMessage = "the grade value to sign cannot be less than ";
        strExMessage += ss.str();
        throw (AForm::GradeTooLowException(strExMessage));
    }
}

void    AForm::isGradeToExecutionValid(int grade)
    throw(AForm::GradeTooLowException, AForm::GradeTooHighException)
{
    std::string strExMessage;

    if (grade < Bureaucrat::HIGH_POSSIBLE_GRADE)
    {
        std::stringstream ss;
        ss << Bureaucrat::HIGH_POSSIBLE_GRADE;
        strExMessage = "the grade value to execute cannot be greater than ";
        strExMessage += ss.str();
        throw (AForm::GradeTooHighException(strExMessage));
    }
    if (grade > Bureaucrat::LOW_POSSIBLE_GRADE)
    {
        std::stringstream ss;
        ss << Bureaucrat::LOW_POSSIBLE_GRADE;
        strExMessage = "the grade value to execute cannot be less than ";
        strExMessage += ss.str();
        throw (AForm::GradeTooLowException(strExMessage));
    }
}


// ---------- nested class(es) ----------

AForm::GradeTooHighException::GradeTooHighException(const std::string &strExMessage)
    : strExMessage(strExMessage){};
AForm::GradeTooHighException::~GradeTooHighException() throw (){};
const char *AForm::GradeTooHighException::what() const throw()
{
    return (strExMessage.c_str());
}

AForm::GradeTooLowException::GradeTooLowException(const std::string &strExMessage)
    : strExMessage(strExMessage){};
AForm::GradeTooLowException::~GradeTooLowException() throw (){};
const char *AForm::GradeTooLowException::what() const throw()
{
    return (strExMessage.c_str());
}

AForm::FormSignException::FormSignException(const std::string &strExMessage)
    : strExMessage(strExMessage){};
AForm::FormSignException::~FormSignException() throw (){};
const char *AForm::FormSignException::what() const throw()
{
    return (strExMessage.c_str());
}

// --- 
std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "Form name:[" << form.getName() << "] " <<
          "is signed:[" << form.isSigned() << "] " <<
          "grade required to sign:[" << form.getGradeRequiredToSign() << "] " <<
          "grade required to execute: [" << form.getGradeRequiredToExecute() << "]";

    return os;
}
