#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>

#include "Contact.hpp"

class PhoneBook
{
    //variables
    private:
        Contact         contacts[8];
        int             intIndexCount;
        int             arrayContactsSize;

    public:
        PhoneBook();
        ~PhoneBook();

        bool    addContact(void);
        bool    search(void) const;
    
    // private methods
    private:
        void        printAllContactsList(void) const;
        int         getIndex(const std::string &input) const;
        std::string getLineUser(const std::string &prompt, bool &eof, bool trimLine) const;
        void        printPhoneBookString(std::string s) const;
};

#endif
