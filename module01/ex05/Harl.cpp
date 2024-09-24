#include "Harl.hpp"

#include <string>
#include <iostream>

// ==================== public functions ==================== 
void    Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
};
void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
};

void    Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
};

void    Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
};

// ==================== private functions ==================== 

void Harl::complain(std::string level)
{
    //make a array to pointers
    void (Harl::*arrayPointerToFunction[4])(void);
    arrayPointerToFunction[0] = &Harl::debug;
    arrayPointerToFunction[1] = &Harl::info;
    arrayPointerToFunction[2] = &Harl::warning;
    arrayPointerToFunction[3] = &Harl::error;

    std::string strsLevels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int count = 0; count < 4; count++)
    {
        if (strsLevels[count] == level)
            (this->*(arrayPointerToFunction[count]))();
    }
};
