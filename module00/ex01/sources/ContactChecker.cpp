#include <string>
#include <iostream>
#include <cctype>

#include "ContactChecker.hpp"
#include "Contact.hpp"

// ==================== public methods ====================

bool	ContactChecker::firstName(const Contact &contact)
{
    return isAValidName(contact);
};

bool	ContactChecker::lastName(const Contact &contact)
{
    (void)contact;
    return isAValidName(contact);
};

bool	ContactChecker::nickname(const Contact &contact)
{
    std::string nickname = contact.getNickname();

    if (nickname.length() == 0)
    {
        std::cout << "The nickname cannot be empty." << std::endl;
        return false;
    }
    (void)contact;
    return true;
};

bool	ContactChecker::phoneNumber(const Contact &contact)
{
    std::string strNumber = contact.getPhoneNumber();
    std::string strInvalidSyntax = "A phone number must have the following syntax (XX)XXXX-XXXX, where X is a number.";

    bool isAValidNumber = true;
    if (strNumber.length() != 13)
    {
        std::cout << strInvalidSyntax << std::endl;
        return false;
    }
    if (strNumber[0] != '(')
        isAValidNumber = false;
    if (!std::isdigit(strNumber[1]) || !std::isdigit(strNumber[2]))
        isAValidNumber = false;
    if (strNumber[3] != ')')
        isAValidNumber = false;
    if (!std::isdigit(strNumber[4]) || !std::isdigit(strNumber[5]) ||
        !std::isdigit(strNumber[6]) || !std::isdigit(strNumber[7]))
        isAValidNumber = false;
    if (strNumber[8] != '-')
        isAValidNumber = false;
    if (!std::isdigit(strNumber[9]) || !std::isdigit(strNumber[10]) ||
        !std::isdigit(strNumber[11]) || !std::isdigit(strNumber[12]))
        isAValidNumber = false;
    if (!isAValidNumber)
        std::cout << strInvalidSyntax << std::endl;
    return isAValidNumber;
};

bool	ContactChecker::secret(const Contact &contact)
{
    (void)contact;
    return true;
};


// ==================== private methods ====================

bool	ContactChecker::isAValidName(const Contact &contact)
{
    std::string strName = contact.getFirstName();

    if (strName.length() == 0)
    {
        std::cout << "A name can't be empty" << std::endl;
        return false;
    }
    for (std::string::const_iterator it = strName.begin(); it != strName.end(); ++it) {
        if (!std::isalpha(static_cast<unsigned char>(*it)) && !std::isspace(*it))
        {
            std::cout << "A name must only contain letters and spaces" << std::endl;
            return false;
        }
    }
    return true;
};

