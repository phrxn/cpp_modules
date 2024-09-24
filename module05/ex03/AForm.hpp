#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

#include <string>

class Bureaucrat;

class AForm
{
    // --- variable(s) ---
    private:
        const std::string   name;
        bool                _isSigned;
        const int           gradeRequiredToSign;
        const int           gradeRequiredToExecute;

    // --- constructor(s) and destructor ---
    private:
        AForm(void);

    public:
        AForm(const std::string &name, int gradeToSign, int gradeToExecute) throw(AForm::GradeTooLowException, AForm::GradeTooHighException);
        AForm(const AForm &form);
        virtual ~AForm();

    // --- function(s) ---
    public:

        //operator(s) overload
        AForm &operator=(const AForm &form);

        //getter(s)
        std::string const   &getName(void) const;
        int                 getGradeRequiredToSign(void) const;
        int                 getGradeRequiredToExecute(void) const;
        bool                isSigned(void) const;

        //other(s)
        void                beSigned(const Bureaucrat &bureaucrat) throw(AForm::FormSignException, AForm::GradeTooLowException);
        void                beforeExecute(const Bureaucrat &bureaucrat) const throw (AForm::FormSignException, AForm::GradeTooLowException);
        virtual void        execute(Bureaucrat const & executor) const = 0;

    private:
        void    isGradeToSignValid(int grade) throw(AForm::GradeTooLowException, AForm::GradeTooHighException);
        void    isGradeToExecutionValid(int grade) throw(AForm::GradeTooLowException, AForm::GradeTooHighException);


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

        class FormSignException : public std::exception
        {
            private:
                std::string strExMessage;

            public:
                FormSignException(const std::string &strExMessage);
                ~FormSignException() throw();

            public:
                virtual const char *what(void) const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
