#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

#include <string>

class Intern
{
    // ----- constructor(s) and destructor -----
    public:
        Intern(void);
        Intern(const Intern &src);
        ~Intern(void);

    // ----- function(s) -----
    public:

        //operator(s) overload
        Intern &operator=(const Intern &rhs);

        //others
        AForm *makeForm(const std::string &name, const std::string &target);

};

#endif
