#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <string>

class Contact
{
    //variables
    private:
        int             index;
        std::string     firstName;
        std::string     lastName;
        std::string     nickname;
        std::string     phoneNumber;
        std::string     secret;
    
    public:
        //constructor(s) and destructor
        Contact();
        Contact(int index, std::string &firstName,
                std::string &lastName, std::string &nickname,
                std::string &phoneNumber,
                std::string &secret);
        Contact(const Contact &contact);
        ~Contact();

        //getters
        void setIndex(int index);
        void setFirstName(std::string &firstName);
        void setLastName(std::string &lastName);
        void setNickname(std::string &nickname);
        void setPhoneNumber(std::string &phoneNumber);
        void setSecret(std::string &secret);

        //setters
        int                 getIndex() const;
        std::string const   &getFirstName(void) const;
        std::string const   &getLastName(void) const;
        std::string const   &getNickname(void) const;
        std::string const   &getPhoneNumber(void) const;
        std::string const   &getSecret(void) const;

        //operator(s) overload
        Contact& operator=(const Contact &contact);
        std::ostream& operator<<(std::ostream& os) const;
    
};

std::ostream& operator<<(std::ostream& os, const Contact &c);

#endif
