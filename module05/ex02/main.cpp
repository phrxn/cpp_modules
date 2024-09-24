#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <string>
#include <stdexcept>

#define COLOR_RESET "\033[0m"
#define COLOR_RED   "\033[91m"
#define COLOR_GREEN "\033[92m"
#define COLOR_MAGENTA  "\033[95m"
#define COLOR_CYAN  "\033[96m"


int main(void)
{

    std::cout << "\n\n" << std::endl;
    {
        std::cout << " %%%%%%%%%%%%%%%%%%% PRESIDENTIAL PARDON FORM %%%%%%%%%%%%%%%%%%% " << std::endl;
        Bureaucrat bigBureaucratSign("BigBureaucratSign", 20); 
        Bureaucrat lowBureaucratSign("LowBureaucratSign", 30); 
        Bureaucrat bigBureaucratExec("BigBureaucratExec", 2); 
        Bureaucrat lowBureaucratExec("LowBureaucratExec", 10); 

        PresidentialPardonForm pForm("Julia");

        std::cout << "==================== The bureaucrats ====================" << std::endl;
        std::cout << bigBureaucratSign << std::endl;
        std::cout << lowBureaucratSign << std::endl;
        std::cout << bigBureaucratExec << std::endl;
        std::cout << lowBureaucratExec << std::endl;

        std::cout << " >>> Grade to sign   : " << pForm.getGradeRequiredToSign() << std::endl;
        std::cout << " >>> Grade to execute: " << pForm.getGradeRequiredToExecute() << std::endl;

        std::cout << "==================== trying to execute without signing ====================" << std::endl;
        bigBureaucratExec.executeForm(pForm);
        lowBureaucratExec.executeForm(pForm);
        std::cout << "==================== trying to sign ====================" << std::endl;
        lowBureaucratSign.signForm(pForm);
        bigBureaucratSign.signForm(pForm);
        std::cout << "==================== AFTER SIGNING: trying to execute with sign ====================" << std::endl;
        std::cout << "\t+++++ trying with lowBureaucrat +++++" << std::endl;
        lowBureaucratExec.executeForm(pForm);
        std::cout << "\n\t+++++ trying with bigBureaucrat +++++" << std::endl;
        bigBureaucratExec.executeForm(pForm);
    }

    std::cout << "\n" << std::endl;

    {
        std::cout << " %%%%%%%%%%%%%%%%%%% ROBOTOMY REQUEST FORM %%%%%%%%%%%%%%%%%%% " << std::endl;
        Bureaucrat bigBureaucratSign("BigBureaucratSign", 72); 
        Bureaucrat lowBureaucratSign("LowBureaucratSign", 100); 
        Bureaucrat bigBureaucratExec("BigBureaucratExec", 35); 
        Bureaucrat lowBureaucratExec("LowBureaucratExec", 55); 

        RobotomyRequestForm pForm("XT-9900");

        std::cout << "==================== The bureaucrats ====================" << std::endl;
        std::cout << bigBureaucratSign << std::endl;
        std::cout << lowBureaucratSign << std::endl;
        std::cout << bigBureaucratExec << std::endl;
        std::cout << lowBureaucratExec << std::endl;

        std::cout << " >>> Grade to sign   : " << pForm.getGradeRequiredToSign() << std::endl;
        std::cout << " >>> Grade to execute: " << pForm.getGradeRequiredToExecute() << std::endl;

        std::cout << "==================== trying to execute without signing ====================" << std::endl;
        bigBureaucratExec.executeForm(pForm);
        lowBureaucratExec.executeForm(pForm);
        std::cout << "==================== trying to sign ====================" << std::endl;
        lowBureaucratSign.signForm(pForm);
        bigBureaucratSign.signForm(pForm);
        std::cout << "==================== AFTER SIGNING: trying to execute with sign ====================" << std::endl;
        std::cout << "\t+++++ trying with lowBureaucrat +++++" << std::endl;
        lowBureaucratExec.executeForm(pForm);
        std::cout << "\n\t+++++ trying with bigBureaucrat +++++" << std::endl;
        bigBureaucratExec.executeForm(pForm);
    }

    std::cout << "\n" << std::endl;

    {
        std::cout << " %%%%%%%%%%%%%%%%%%% SHRUBBERY CREATION FORM %%%%%%%%%%%%%%%%%%% " << std::endl;
        Bureaucrat bigBureaucratSign("BigBureaucratSign", 130); 
        Bureaucrat lowBureaucratSign("LowBureaucratSign", 149); 
        Bureaucrat bigBureaucratExec("BigBureaucratExec", 100); 
        Bureaucrat lowBureaucratExec("LowBureaucratExec", 150); 

        ShrubberyCreationForm pForm("The forest");

        std::cout << "==================== The bureaucrats ====================" << std::endl;
        std::cout << bigBureaucratSign << std::endl;
        std::cout << lowBureaucratSign << std::endl;
        std::cout << bigBureaucratExec << std::endl;
        std::cout << lowBureaucratExec << std::endl;

        std::cout << " >>> Grade to sign   : " << pForm.getGradeRequiredToSign() << std::endl;
        std::cout << " >>> Grade to execute: " << pForm.getGradeRequiredToExecute() << std::endl;

        std::cout << "==================== trying to execute without signing ====================" << std::endl;
        bigBureaucratExec.executeForm(pForm);
        lowBureaucratExec.executeForm(pForm);
        std::cout << "==================== trying to sign ====================" << std::endl;
        lowBureaucratSign.signForm(pForm);
        bigBureaucratSign.signForm(pForm);
        std::cout << "==================== AFTER SIGNING: trying to execute with sign ====================" << std::endl;
        std::cout << "\t+++++ trying with lowBureaucrat +++++" << std::endl;
        lowBureaucratExec.executeForm(pForm);
        std::cout << "\n\t+++++ trying with bigBureaucrat +++++" << std::endl;
        bigBureaucratExec.executeForm(pForm);
    }
    std::cout << "\n" << std::endl;
    return (0);
}
