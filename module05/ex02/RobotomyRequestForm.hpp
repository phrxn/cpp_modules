#ifndef ROBOTOMY_REQUEST_FORM_HPP 
#define ROBOTOMY_REQUEST_FORM_HPP 

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    // --- variable(s) ---
    private:
        const std::string target;

    public:
        static const int MIN_GRADE_TO_SIGN = 72;
        static const int MIN_GRADE_TO_EXEC = 45;

    // --- constructor(s) and destructor ---
    private:
        RobotomyRequestForm(void);

    public:
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &form);
        ~RobotomyRequestForm(void);

    // --- functions ---
    public:

        //operator(s) overload
        RobotomyRequestForm &operator=(RobotomyRequestForm &rhs);

        //others
        void        execute(Bureaucrat const &executor) const;
        std::string getTarget(void) const;
};

#endif
