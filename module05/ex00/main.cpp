#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

#define COLOR_RESET "\033[0m"
#define COLOR_RED   "\033[91m"
#define COLOR_GREEN "\033[92m"
#define COLOR_MAGENTA  "\033[95m"
#define COLOR_CYAN  "\033[96m"

void createBureaucrat(const std::string &name, int grade)
{
    std::cout << "Trying create the bureaucrat: " << COLOR_CYAN << name << COLOR_RESET << ", with grade: " << grade << std::endl;

    try
    {
        Bureaucrat bureaucrat(name, grade);
        std::cout << COLOR_GREEN << "Successfully! " << COLOR_RESET
                  << "The bureaucrat: " << COLOR_CYAN << name << COLOR_RESET << 
                  ", with grade: " << grade << 
                  " was created." << std::endl;
    }
    catch(const Bureaucrat::GradeTooHighException &ex)
    {
        std::cout << COLOR_RED << "Error: " << COLOR_RESET << "Unable to create bureaucrat: "
                     COLOR_CYAN << name << COLOR_RESET << ": " << COLOR_MAGENTA << ex.what() << COLOR_RESET << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException &ex)
    {
        std::cout << COLOR_RED << "Error: " << COLOR_RESET <<
                    "Unable to create bureaucrat: " << 
                    COLOR_CYAN << name << COLOR_RESET << ": " << COLOR_MAGENTA << ex.what() << COLOR_RESET << std::endl;
    }
}

int main(void)
{
    std::cout << "\n================ Trying create the bureaucrats from constructor ================\n" << std::endl;
    createBureaucrat("The big bureaucrat", 1);
    std::cout << "\n\t\t\t***\t\t\t\n" << std::endl;
    createBureaucrat("The poor trainne", 150);
    std::cout << "\n\t\t\t***\t\t\t\n" << std::endl;
    createBureaucrat("The REALLY bureaucrat", 0);
    std::cout << "\n\t\t\t***\t\t\t\n" << std::endl;
    createBureaucrat("The REALLY poor trainne", 151);

    {
        std::cout << "\n\n====================== trying 2 -> 1 and 1 -> 0 ====================== \t\t\t\n" << std::endl;
        std::string name = "The Big Brother";
        int grade = 2;
        try
        {
            std::cout << "\t"; Bureaucrat bureaucrat(name, grade); std::cout << std::flush;
            std::cout << COLOR_GREEN << "\tSuccessfully! " << COLOR_RESET
                      << "\tThe bureaucrat: " << COLOR_CYAN << name << COLOR_RESET << 
                      ", with grade: " << grade << 
                      " was created." << std::endl;
            std::cout << "\t" << bureaucrat << std::endl; 
            std::cout << std::endl;
            std::cout << "\ttrying to increase the " << COLOR_CYAN << name << COLOR_RESET << ", from " 
                      << COLOR_CYAN << grade << COLOR_RESET << " to " << COLOR_CYAN << (grade - 1) << COLOR_RESET << std::endl;
            std::cout << "\tincreasing the " << COLOR_CYAN << name << "'s " COLOR_RESET << " grade" << std::endl; 
            std::cout << "\t"; bureaucrat.incrementGrade(); std::cout << std::flush;
            std::cout << "\tincreasing the " << COLOR_CYAN << name << "'s " COLOR_RESET << " grade again... but..." << std::endl; 
            std::cout << "\t"; bureaucrat.incrementGrade(); std::cout << std::flush;
        }
        catch(const Bureaucrat::GradeTooHighException &ex)
        {
            std::cout << COLOR_RED "\tError: " COLOR_RESET 
                        "It was not possible to increase bureaucrat "
                         COLOR_CYAN << name << COLOR_RESET 
                        "'s grade: "
                        COLOR_MAGENTA << ex.what() << COLOR_RESET
                        << std::endl;
        }
        catch(const Bureaucrat::GradeTooLowException &ex)
        {
            std::cout << COLOR_RED "\tError: " COLOR_RESET 
                        "It was not possible to lower bureaucrat "
                         COLOR_CYAN << name << COLOR_RESET 
                        "'s grade: "
                        COLOR_MAGENTA << ex.what() << COLOR_RESET
                        << std::endl;
        }
    }

    {
        std::cout << "\n\n====================== trying 149 -> 150 and 150 -> 151 ====================== \t\t\t\n" << std::endl;
        std::string name = "Winston Smith";
        int grade = 149;
        try
        {
            std::cout << "\t"; Bureaucrat bureaucrat(name, grade); std::cout << std::flush;
            std::cout << COLOR_GREEN << "\tSuccessfully! " << COLOR_RESET
                      << "\tThe bureaucrat: " << COLOR_CYAN << name << COLOR_RESET << 
                      ", with grade: " << grade << 
                      " was created." << std::endl;
            std::cout << "\t" << bureaucrat << std::endl; 
            std::cout << std::endl;
            std::cout << "\ttrying to increase the " << COLOR_CYAN << name << COLOR_RESET << ", from " 
                      << COLOR_CYAN << grade << COLOR_RESET << " to " << COLOR_CYAN << (grade + 1) << COLOR_RESET << std::endl;
            std::cout << "\tdecreasing the " << COLOR_CYAN << name << "'s " COLOR_RESET << " grade" << std::endl; 
            std::cout << "\t"; bureaucrat.decrementGrade(); std::cout << std::flush;
            std::cout << "\tdecreasing the " << COLOR_CYAN << name << "'s " COLOR_RESET << " grade again... but..." << std::endl; 
            std::cout << "\t"; bureaucrat.decrementGrade(); std::cout << std::flush;
        }
        catch(const Bureaucrat::GradeTooHighException &ex)
        {
            std::cout << COLOR_RED "\tError: " COLOR_RESET 
                        "It was not possible to increase bureaucrat "
                         COLOR_CYAN << name << COLOR_RESET 
                        "'s grade: "
                        COLOR_MAGENTA << ex.what() << COLOR_RESET
                        << std::endl;
        }
        catch(const Bureaucrat::GradeTooLowException &ex)
        {
            std::cout << COLOR_RED "\tError: " COLOR_RESET 
                        "It was not possible to lower bureaucrat "
                         COLOR_CYAN << name << COLOR_RESET 
                        "'s grade: "
                        COLOR_MAGENTA << ex.what() << COLOR_RESET
                        << std::endl;
        }
    }
}
