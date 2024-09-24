#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>
#include <string>
#include <stdexcept>

#define COLOR_RESET "\033[0m"
#define COLOR_RED   "\033[91m"
#define COLOR_GREEN "\033[92m"
#define COLOR_MAGENTA  "\033[95m"
#define COLOR_CYAN  "\033[96m"

void createForm(const std::string &name, int gradeToSign, int gradeToExecute)
{
    std::cout << "Trying create the form: " 
              << COLOR_CYAN << name << COLOR_RESET 
              << ", with grade to sign: " 
              << COLOR_CYAN << gradeToSign << COLOR_RESET
              << ", with grade to excute: " 
              << COLOR_CYAN << gradeToExecute << COLOR_RESET
              << std::endl;

    try
    {
        Form form(name, gradeToSign, gradeToExecute);
        std::cout << COLOR_GREEN << "Successfully! " << COLOR_RESET
                  << "The form: " << COLOR_CYAN << name << COLOR_RESET
                  << ", with grade to sign: " 
                  << COLOR_CYAN << gradeToSign << COLOR_RESET
                  << ", with grade to execute: " 
                  << COLOR_CYAN << gradeToExecute << COLOR_RESET
                  << " was created."
                  << std::endl;
    }
    catch(const Form::GradeTooHighException &ex)
    {
        std::cout << COLOR_RED << "Error: " << COLOR_RESET
                  << "Unable to create form: "
                  << COLOR_CYAN << name << COLOR_RESET
                  << ": "
                  << COLOR_MAGENTA << ex.what() << COLOR_RESET
                  << std::endl;
    }
    catch(const Form::GradeTooLowException &ex)
    {
        std::cout << COLOR_RED << "Error: " << COLOR_RESET
                  << "Unable to create form: "
                  << COLOR_CYAN << name << COLOR_RESET
                  << ": "
                  << COLOR_MAGENTA << ex.what() << COLOR_RESET
                  << std::endl;
    }
}

int main(void)
{
    std::cout << "\n================================ Trying create the forms from constructor ================================\n" << std::endl;

    //valid forms
    std::cout << "\n\t ++++++++++++ Valid forms ++++++++++++\n" << std::endl;
    createForm("request to enter the Ministry of Love", 1, 1);
    std::cout << "\n\t\t\t***\t\t\t\n" << std::endl;
    createForm("request to get more gin", 150, 150);

    //invalid forms
    std::cout << "\n\t ++++++++++++ invalid forms ++++++++++++\n" << std::endl;
    createForm("produce food", 0, 5);
    std::cout << "\n\t\t\t***\t\t\t\n" << std::endl;
    createForm("produce misery ", 151, 10);
    std::cout << "\n\t\t\t***\t\t\t\n" << std::endl;
    createForm("produce freedom", 1, 0);
    std::cout << "\n\t\t\t***\t\t\t\n" << std::endl;
    createForm("produce peace", 10, 151);


    try
    {
        {
            std::cout << "\n================================ TEST FORM COPY ================================\n" << std::endl;
            Form formFrom("formFrom", 42, 42);
            std::cout << "Form from => " << formFrom << std::endl;
            Form formTo(formFrom);
            std::cout << "Form to   => " << formFrom << std::endl;
        }
        {
            std::cout << "\n================================ TEST FORM ASSIGMENT ================================\n" << std::endl;
            Form formFrom("formFrom", 42, 42);
            std::cout << "Form from => " << formFrom << std::endl;
            Form formTo = formFrom;
            std::cout << "Form to   => " << formFrom << std::endl;
        }

    }
    catch(const std::exception &ex)
    {
        std::cout << "An error occurs: " 
                  << COLOR_MAGENTA << ex.what() << COLOR_RESET
                  << std::endl;
    }

    std::cout << "\n" << std::endl;


    std::cout << "\n================================ TEST SIGNATURE ================================\n" << std::endl;
    try
    {
        std::cout << "\n\t ++++++++++++ Valid bureaucrat ++++++++++++\n" << std::endl;
        Bureaucrat bureaucrat1("The Big Brother", 1);
#ifndef DEBUG
        std::cout << bureaucrat1 << std::endl;
#endif
        Form    formWarRequest("War against Oceania", 1, 1);

        std::cout <<  formWarRequest << " signed?" << std::endl;
        bureaucrat1.signForm(formWarRequest);
        std::cout <<  formWarRequest << " signed?" << std::endl;

        //
        std::cout << "\n\t\t ++++++++ trying to sign again ++++++++\n" << std::endl;
        bureaucrat1.signForm(formWarRequest);
    }
    catch(const std::exception &ex)
    {
        std::cout << COLOR_RED << "Error: " << COLOR_RESET
                  << COLOR_MAGENTA << ex.what() << COLOR_RESET
                  << std::endl;
    }
    std::cout << "\n" << std::endl;
    try
    {
        std::cout << "\n\t ++++++++++++ invalid bureaucrat ++++++++++++\n" << std::endl;
        Bureaucrat bureaucrat1("O'Brien", 20);
#ifndef DEBUG
        std::cout << bureaucrat1 << std::endl;
#endif
        Form    formWarRequest("War against Oceania", 1, 1);

        std::cout <<  formWarRequest << " signed?" << std::endl;
        bureaucrat1.signForm(formWarRequest);
        std::cout <<  formWarRequest << " signed?" << std::endl;
    }
    catch(const std::exception &ex)
    {
        std::cout << COLOR_RED << "Error: " << COLOR_RESET
                  << COLOR_MAGENTA << ex.what() << COLOR_RESET
                  << std::endl;
    }
}
