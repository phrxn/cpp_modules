#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>
#include <iostream>

class Bureaucrat
{
    // --- forward class(es) ---
    public:
        class GradeTooHighException;
        class GradeTooLowException;
        
    // --- variable(s) ----
    private:
        const std::string   name;
        int                 grade;

    public:
        static const int HIGH_POSSIBLE_GRADE = 1;
        static const int LOW_POSSIBLE_GRADE = 150;

    // --- constructor(s) and destructor ---
    private:
        Bureaucrat(void);

    public:
        Bureaucrat(const Bureaucrat &bureaucrat);
        Bureaucrat(const std::string &name, int grade) throw(Bureaucrat::GradeTooLowException, Bureaucrat::GradeTooHighException);
        ~Bureaucrat(void);

    // --- functions ---
    public:

        //operator(s) overload
        Bureaucrat &operator=(const Bureaucrat &bureaucrat);

        //getter(s)
        std::string const   &getName(void) const;
        int                 getGrade(void) const;

        //others
        void incrementGrade(void) throw(Bureaucrat::GradeTooLowException, Bureaucrat::GradeTooHighException);
        void decrementGrade(void) throw(Bureaucrat::GradeTooLowException, Bureaucrat::GradeTooHighException);

    private:
        void isGradeValid(int grade) throw(Bureaucrat::GradeTooLowException, Bureaucrat::GradeTooHighException);

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
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
