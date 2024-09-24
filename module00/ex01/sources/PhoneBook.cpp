#include <iostream>
#include <string>
#include <iomanip>

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "ContactChecker.hpp"

/** trim - remove initial and end spaces from string
 *
 * @toTrim: the string to trim
 *
 * Return:
 *  the trimmed string. (If string is only spaces, a empty string is returned)
 */
std::string trim(const std::string &toTrim)
{
    std::string::size_type start = 0;
    std::string::size_type end = toTrim.length();

    while(start < toTrim.length() && std::isspace(toTrim[start]))
        start++;
    while(end > 0 && std::isspace(toTrim[end - 1]))
        end--;
    return toTrim.substr(start, (end - start));
}

PhoneBook::PhoneBook()
                    :
                    intIndexCount(-1), arrayContactsSize(0){};
PhoneBook::~PhoneBook()
{
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
std::string PhoneBook::getLineUser(const std::string &prompt, bool &eof, bool trimLine) const
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
    }
    if (trimLine)
        return trim(line);
    return line;
}

bool    PhoneBook::addContact(void)
{
    Contact         contactTmp;
    ContactChecker  contactChecker;
    std::string     inputLine;
    bool            eof = false;

    intIndexCount++;
    if (intIndexCount > 7)
        this->intIndexCount = 0;
    if (arrayContactsSize < 8)
        this->arrayContactsSize++;

    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|----------- Create a new Contact ----------|" << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << std::endl;
   
    //set first name
    do
    {
        inputLine = getLineUser("User first name:\n> ", eof, true);
        if (eof)
            return false;
        contactTmp.setFirstName(inputLine);
        if (contactChecker.firstName(contactTmp))
            break ;
    }while(true);

    //set last name
    do
    {
        inputLine = getLineUser("User last name:\n> ", eof, true);
        if (eof)
            return false;
        contactTmp.setLastName(inputLine);
        if (contactChecker.lastName(contactTmp))
            break ;
    }while(true);

    do
    {
        inputLine = getLineUser("User nickname:\n> ", eof, true);
        if (eof)
            return false;
        contactTmp.setNickname(inputLine);
        if (contactChecker.nickname(contactTmp))
            break ;
    }while(true);

    do
    {
        inputLine = getLineUser("User phone number:\n> ", eof, true);
        if (eof)
            return false;
        contactTmp.setPhoneNumber(inputLine);
        if (contactChecker.phoneNumber(contactTmp))
            break ;
    }while(true);

    do
    {
        inputLine = getLineUser("User darkest secret!:\n> ", eof, true);
        if (eof)
            return false;
        contactTmp.setSecret(inputLine);
        if (contactChecker.secret(contactTmp))
            break ;
    }while(true);
    contacts[intIndexCount] = contactTmp;
    std::cout << "  **The user was added**!" << std::endl;
    std::cout << "\nType enter to continue.." << std::endl;
    std::cin.get();
    return true;
}

bool    PhoneBook::search() const
{
    std::string userInput;
    int         userIndex;
    bool        eof;

    if (this->arrayContactsSize == 0)
    {
        std::cout << "Empty phonebook!\nType enter to continue.." << std::endl;
        std::cin.get();
        return true;
    }


    std::cout	<< "\n--------------- The Phonebook ---------------\n" << std::endl;
    printAllContactsList();

    do
    {
        userInput = getLineUser("Insert a index to show the informations: ", eof, false); 
        if (eof)
            return false;
        userIndex = getIndex(userInput);
        if (userIndex != -1)
            break ;
        std::cout << "invalid index, please insert a valid index!" << std::endl;
    } while(userIndex == -1);

    std::cout << contacts[userIndex] << std::flush;
    std::cout << "\nType enter to continue.." << std::endl;
    std::cin.get();
    return true;
}

void    PhoneBook::printAllContactsList() const
{
    std::cout	<< "---------------------------------------------" << std::endl
                << "|  Index   |First Name|Last Name | Nickname |" << std::endl
				<< "---------------------------------------------" << std::endl;
    for(int count_contact = 0; count_contact < this->arrayContactsSize; count_contact++)
    {
        std::cout << "|" << std::setw(10) << count_contact << "|";
        printPhoneBookString(this->contacts[count_contact].getFirstName());
        printPhoneBookString(this->contacts[count_contact].getLastName());
        printPhoneBookString(this->contacts[count_contact].getNickname());
        std::cout << std::endl;
    }
	std::cout << "---------------------------------------------" << std::endl;
}

//==================== private methods ==================== 

void    PhoneBook::printPhoneBookString(std::string s) const
{
    if (s.length() >= 10)
    {
        s.resize(9);
        s+= ".";
    }
    std::cout << std::setw(10) << s << "|"; 
}

/**
 * getIndex - convert a input in a valid index.
 *
 * Return:
 *  On successful:
 *      a int value between 0 and 7
 *  On failure:
 *      -1 is returned
 */
int     PhoneBook::getIndex(const std::string &input) const
{
    int index = -1;
    if (input.length() != 1)
        return index;
    if (!std::isdigit(input[0]))
        return index;
    index = input[0] - '0';
    if (index >= arrayContactsSize)
        return -1;
    return (index);
}
