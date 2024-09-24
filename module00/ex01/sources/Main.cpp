#include <string>
#include <iostream>
#include <cctype>

#include "Contact.hpp"
#include "PhoneBook.hpp"

void showMainMenu()
{
    std::cout << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|---------------- Main Menu ----------------|" << std::endl;
    std::cout << "|                                           |" << std::endl;
    std::cout << "|Options: write one of the option           |" << std::endl;
    std::cout << "|                                           |" << std::endl;
    std::cout << "|ADD:    to add a new contact               |" << std::endl;
    std::cout << "|SEARCH: to see the details of a contact    |" << std::endl;
    std::cout << "|EXIT:   to exit                            |" << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
}

/**
 * getLine - read a line from STDIN and retorna the line trimmed
 *
 * @prompt: text that will be displayed to the user
 * @eof:    variable to know if eof was reached. this variable is ALWAYS
 *          filled inside the function.
 * 
 * Return:
 *  On successfull:
 *      A trimmed line (this line can be empty)
 *  On failure or hited EOL:
 *      "EXIT" is returned
 */
std::string getLineUser(const std::string &prompt, bool &eof)
{
    std::string line;
    
    eof = false;
    if (std::cin.eof())
    {
        eof = true;
        return ("");
    }
    std::cout << prompt << std::flush;
    std::getline(std::cin, line);
    if (std::cin.eof())
    {
        eof = true;
        std::cout << std::endl;
        return ("");
    }
    return line;
}

void    clearTerminal()
{
    std::cout << "\033[2J\033[1;1H" << std::endl;
}

int main(void)
{
    bool endOfFile = false;
    std::string line;
    PhoneBook phoneBook;

    std::cout << std::endl;
    std::cout << "Amnesia phonebook! The best phonebook in the world!" << std::endl;
    std::cout << "The Amnesia is... well... hmmm... Ah! The best phonebook in the world!" << std::endl;
    std::cout << std::endl;
    while(true)
    {
        if (endOfFile)
            break ;
        showMainMenu();
        line = getLineUser("> ", endOfFile);
        if (endOfFile)
            break ;
        if (line == "EXIT")
            break ;
        if (line == "SEARCH")
        {
            clearTerminal();
            if (!phoneBook.search())
                break ;
            clearTerminal();
            continue;
        }
        if (line == "ADD")
        {
            clearTerminal();
            if (!phoneBook.addContact())
                break;
            clearTerminal();
            continue;
        }
        clearTerminal();
        std::cout << "Please, write a valid input" << std::endl;            
    }
    return (0);
}
