#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cerrno>


const std::string ShrubberyCreationForm::SHRUBBERY =
"\n"
"       _-_\n"
"    /~~   ~~\\\n"
"  /~~ o  o  ~~\\\n"
" { o  ~ o  o ~ }\n"
" \\ o_-     -_  /\n"
"   ~  \\ //  ~\n"
"       |||   \\/\n"
"    o  |||_/_/\n"
"     \\_|||  \\/\n"
"   \\/  |||__/\n"
"    \\__|||\n"
"       |||\n";


// --- constructor(s) and destructor ---
//private constructor
ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("ShrubberyCreationForm", MIN_GRADE_TO_SIGN, MIN_GRADE_TO_EXEC),
    target("--")
{
    std::cout << "ShrubberyCreationForm: overloaded default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", MIN_GRADE_TO_SIGN, MIN_GRADE_TO_EXEC) ,
    target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form)
    : AForm(form),
    target(form.target)
{
    std::cout << "ShrubberyCreationForm: overloaded copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm: overloaded destructor called" << std::endl;
}

//operator(s) overload
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &rhs)
{
    (void) rhs;

    std::cout << "ShrubberyCreationForm: overloaded assignment operator called" << std::endl;
    return (*this);
}

//others
void        ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    std::ofstream   ofsFile;
    std::string     fileName = target + "_shrubbery";

    beforeExecute(executor);
    ofsFile.open(fileName.c_str());

    if (!ofsFile.is_open())
    {
        std::string strThrowMessageError;

        strThrowMessageError += "Unable to open the file ";
        strThrowMessageError += fileName;
        strThrowMessageError += ": ";
        strThrowMessageError += strerror(errno);

        throw ShrubberyCreationForm::FileException(strThrowMessageError);
    }
    ofsFile << SHRUBBERY;
    ofsFile.close();
}

std::string ShrubberyCreationForm::getTarget(void) const
{
    return (this->target);
}

ShrubberyCreationForm::FileException::FileException(const std::string &strExMessage)
    : strExMessage(strExMessage){};
ShrubberyCreationForm::FileException::~FileException() throw (){};
const char *ShrubberyCreationForm::FileException::what() const throw()
{
    return (strExMessage.c_str());
}
