#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    // --- variable(s) ---
    private:
        static const std::string    SHRUBBERY;
        const std::string target;

    public:
        static const int            MIN_GRADE_TO_SIGN = 145;
        static const int            MIN_GRADE_TO_EXEC = 137;

    // --- constructor(s) and destructor ---
    private:
        ShrubberyCreationForm(void);

    public:
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &form);
        ~ShrubberyCreationForm(void);

    // --- functions ---
    public:

        //operator(s) overload
        ShrubberyCreationForm &operator=(ShrubberyCreationForm &rhs);

        //others
        void        execute(Bureaucrat const &executor) const;
        std::string getTarget(void) const;

    // --- nested class(es)
    class FileException;

    // -- nested class(es) ---
    public:
        class FileException : public std::exception
        {
            private:
                std::string strExMessage;

            public:
                FileException(const std::string &strExMessage);
                ~FileException(void) throw();

            public:
                virtual const char *what(void) const throw();
        };
};

#endif
