#include "Bureaucrat.hpp"
#include "AForm.hpp"

//#include "ShrubberyCreationForm.hpp"
//#include "RobotomyRequestForm.hpp"
//#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <string>
#include <stdexcept>

#include "Intern.hpp"

#define COLOR_RESET "\033[0m"
#define COLOR_RED   "\033[91m"
#define COLOR_GREEN "\033[92m"
#define COLOR_MAGENTA  "\033[95m"
#define COLOR_CYAN  "\033[96m"


void createForm(Intern &intern, const std::string &formName, const std::string &target)
{
    AForm *theForm = 0;

    theForm = intern.makeForm(formName, target);
    if (theForm == 0)
        return;

    Bureaucrat bigBureaucratSign("BigBureaucratSign", 1);                  
    Bureaucrat lowBureaucratSign("LowBureaucratSign", 150);                  
    Bureaucrat bigBureaucratExec("BigBureaucratExec", 1);                   
    Bureaucrat lowBureaucratExec("LowBureaucratExec", 150);                  
                                                     
    std::cout << "==================== The bureaucrats ====================" << std::endl;
    std::cout << bigBureaucratSign << std::endl;                            
    std::cout << lowBureaucratSign << std::endl;                            
    std::cout << bigBureaucratExec << std::endl;                            
    std::cout << lowBureaucratExec << std::endl;                            

    std::cout << " >>> Grade to sign   : " << theForm->getGradeRequiredToSign() << std::endl;
    std::cout << " >>> Grade to execute: " << theForm->getGradeRequiredToExecute() << std::endl;

    std::cout << "==================== trying to execute without signing ====================" << std::endl;
    bigBureaucratExec.executeForm(*theForm);                                   
    lowBureaucratExec.executeForm(*theForm);                                   
    std::cout << "==================== trying to sign ====================" << std::endl;
    lowBureaucratSign.signForm(*theForm);                                      
    bigBureaucratSign.signForm(*theForm);                                      
    std::cout << "==================== AFTER SIGNING: trying to execute with sign ====================" << std::endl;
    std::cout << "\t+++++ trying with lowBureaucrat +++++" << std::endl;    
    lowBureaucratExec.executeForm(*theForm);                                   
    std::cout << "\n\t+++++ trying with bigBureaucrat +++++" << std::endl;  
    bigBureaucratExec.executeForm(*theForm);   

    delete theForm;
}


int main(void)
{
    std::cout << std::endl;
    Intern i;
    std::cout << "\n\n" << std::endl;
    createForm(i, "invalid form name", "---");
    std::cout << "\n\n *************************************** \n" << std::endl;
    createForm(i, "presidential pardon", "Julia");
    std::cout << "\n\n *************************************** \n" << std::endl;
    createForm(i, "robotomy request", "ZK9-BT9900");
    std::cout << "\n\n *************************************** \n" << std::endl;
    createForm(i, "shrubbery creation", "Forest");
    std::cout << "\n\n *************************************** \n" << std::endl;
    return 0;
}
