#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

#include <string>

class Bureaucrat;

class Form
{
    // --- variable(s) ---
    private:
        const std::string   name;
        bool                _isSigned;
        const int           gradeRequiredToSign;
        const int           gradeRequiredToExecute;

    // --- constructor(s) and destructor ---
    private:
        Form(void);

    public:
        Form(const std::string &name, int gradeToSign, int gradeToExecute) throw(Form::GradeTooLowException, Form::GradeTooHighException);
        Form(const Form &form);
        ~Form();

    // --- function(s) ---
    public:

        //operator(s) overload
        Form &operator=(const Form &form);

        //getter(s)
        std::string const   &getName(void) const;
        int                 getGradeRequiredToSign(void) const;
        int                 getGradeRequiredToExecute(void) const;
        bool                isSigned(void) const;

        //other(s)
        void                beSigned(const Bureaucrat &bureaucrat) throw(Form::FormAlreadySignedException, Form::GradeTooLowException);


    private:
        void    isGradeToSignValid(int grade) throw(Form::GradeTooLowException, Form::GradeTooHighException);
        void    isGradeToExecutionValid(int grade) throw(Form::GradeTooLowException, Form::GradeTooHighException);


    // -- nested class(es) ---
    public:
        class GradeTooHighException : public std::exception
        {
            private:
                std::string strExMessage;

            public:
                GradeTooHighException(const std::string &strExMessage);
                ~GradeTooHighException(void) throw();

            public:
                virtual const char *what(void) const throw();
        };

        class GradeTooLowException : public std::exception
        {
            private:
                std::string strExMessage;

            public:
                GradeTooLowException(const std::string &strExMessage);
                ~GradeTooLowException() throw();

            public:
                virtual const char *what(void) const throw();
        };

        class FormAlreadySignedException : public std::exception
        {
            private:
                std::string strExMessage;

            public:
                FormAlreadySignedException(const std::string &strExMessage);
                ~FormAlreadySignedException() throw();

            public:
                virtual const char *what(void) const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
