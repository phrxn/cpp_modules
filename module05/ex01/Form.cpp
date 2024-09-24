#include "Form.hpp"

#include <sstream>

Form::Form(void) :
    name ("--"),
    _isSigned(false),
    gradeRequiredToSign(1),
    gradeRequiredToExecute(1)
{
#ifdef DEBUG
    std::cout << "Form:  overloaded default constructor called" << std::endl;
#endif
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    throw(Form::GradeTooLowException, Form::GradeTooHighException) :
        name(name),
        _isSigned(false),
        gradeRequiredToSign(gradeToSign),
        gradeRequiredToExecute(gradeToExecute)
{
#ifdef DEBUG
    std::cout << "Form:  name, granToSign and gradeToExecute constructor called" << std::endl;
#endif
    isGradeToSignValid(gradeToSign);
    isGradeToExecutionValid(gradeToExecute);
}

Form::Form(const Form &form) :
    name (form.name),
    gradeRequiredToSign(form.gradeRequiredToSign),
    gradeRequiredToExecute(form.gradeRequiredToExecute)
{
#ifdef DEBUG
    std::cout << "Form:  overloaded copy constructor called" << std::endl;
#endif
    *this = form;
}

Form::~Form()
{
#ifdef DEBUG
    std::cout << "Form:  overloaded destructor called" << std::endl;
#endif
}

Form &Form::operator=(const Form &form)
{
#ifdef DEBUG
    std::cout << "Form: overloaded assignment operator called" << std::endl;
#endif

    if (this == &form) return *this;

    this->_isSigned = form._isSigned;

    return *this;
}

std::string const   &Form::getName(void) const
{
    return (this->name);
}
int                 Form::getGradeRequiredToSign(void) const
{
    return (this->gradeRequiredToSign);
}
int                 Form::getGradeRequiredToExecute(void) const
{
    return (this->gradeRequiredToExecute);
}
bool                Form::isSigned(void) const
{
    return (this->_isSigned);
}

void                Form::beSigned(const Bureaucrat &bureaucrat)
    throw(Form::FormAlreadySignedException, Form::GradeTooLowException)
{
    if (_isSigned)
        throw (Form::FormAlreadySignedException("The form is already signed"));
    if(bureaucrat.getGrade() > this->gradeRequiredToSign)
        throw(Form::GradeTooLowException("The bureaucrat's grade is smaller than necessary"));
    this->_isSigned = true;
}

void    Form::isGradeToSignValid(int grade)
    throw(Form::GradeTooLowException, Form::GradeTooHighException)
{
    std::string strExMessage;

    if (grade < Bureaucrat::HIGH_POSSIBLE_GRADE)
    {
        std::stringstream ss;
        ss << Bureaucrat::HIGH_POSSIBLE_GRADE;
        strExMessage = "the grade value to sign cannot be greater than ";
        strExMessage += ss.str();
        throw (Form::GradeTooHighException(strExMessage));
    }
    if (grade > Bureaucrat::LOW_POSSIBLE_GRADE)
    {
        std::stringstream ss;
        ss << Bureaucrat::LOW_POSSIBLE_GRADE;
        strExMessage = "the grade value to sign cannot be less than ";
        strExMessage += ss.str();
        throw (Form::GradeTooLowException(strExMessage));
    }
}

void    Form::isGradeToExecutionValid(int grade)
    throw(Form::GradeTooLowException, Form::GradeTooHighException)
{
    std::string strExMessage;

    if (grade < Bureaucrat::HIGH_POSSIBLE_GRADE)
    {
        std::stringstream ss;
        ss << Bureaucrat::HIGH_POSSIBLE_GRADE;
        strExMessage = "the grade value to execute cannot be greater than ";
        strExMessage += ss.str();
        throw (Form::GradeTooHighException(strExMessage));
    }
    if (grade > Bureaucrat::LOW_POSSIBLE_GRADE)
    {
        std::stringstream ss;
        ss << Bureaucrat::LOW_POSSIBLE_GRADE;
        strExMessage = "the grade value to execute cannot be less than ";
        strExMessage += ss.str();
        throw (Form::GradeTooLowException(strExMessage));
    }
}

// ---------- nested class(es) ----------

Form::GradeTooHighException::GradeTooHighException(const std::string &strExMessage)
    : strExMessage(strExMessage){};
Form::GradeTooHighException::~GradeTooHighException() throw (){};
const char *Form::GradeTooHighException::what() const throw()
{
    return (strExMessage.c_str());
}

Form::GradeTooLowException::GradeTooLowException(const std::string &strExMessage)
    : strExMessage(strExMessage){};
Form::GradeTooLowException::~GradeTooLowException() throw (){};
const char *Form::GradeTooLowException::what() const throw()
{
    return (strExMessage.c_str());
}

Form::FormAlreadySignedException::FormAlreadySignedException(const std::string &strExMessage)
    : strExMessage(strExMessage){};
Form::FormAlreadySignedException::~FormAlreadySignedException() throw (){};
const char *Form::FormAlreadySignedException::what() const throw()
{
    return (strExMessage.c_str());
}

// --- 
std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form name:[" << form.getName() << "] " <<
          "is signed:[" << form.isSigned() << "] " <<
          "grade required to sign:[" << form.getGradeRequiredToSign() << "] " <<
          "grade required to execute: [" << form.getGradeRequiredToExecute() << "]";

    return os;
}
