#ifndef CONTACT_CHECKER_HPP
#define CONTACT_CHECKER_HPP

#include "Contact.hpp"

class ContactChecker
{
    public:
        bool    firstName(const Contact &contact);
        bool	lastName(const Contact &contact);
        bool	nickname(const Contact &contact);
        bool	phoneNumber(const Contact &contact);
        bool	secret(const Contact &contact);

    private:
        bool    isAValidName(const Contact &contact);
};

#endif

