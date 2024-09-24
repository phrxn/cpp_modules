#ifndef PRESIDENTIAL_PARDON_FORM_HPP 
#define PRESIDENTIAL_PARDON_FORM_HPP 

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    // --- variable(s) ---
    private:
        const std::string target;

    public:
        static const int MIN_GRADE_TO_SIGN = 25;
        static const int MIN_GRADE_TO_EXEC = 5;

    // --- constructor(s) and destructor ---
    private:
        PresidentialPardonForm(void);

    public:
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &form);
        ~PresidentialPardonForm(void);

    // --- functions ---
    public:

        //operator(s) overload
        PresidentialPardonForm &operator=(PresidentialPardonForm &rhs);

        //others
        void        execute(Bureaucrat const &executor) const;
        std::string getTarget(void) const;
};

#endif
