#include "Contact.hpp"
#include <iostream>

Contact::Contact(int index, std::string &firstName,
                std::string &lastName, std::string &nickname,
                std::string &phoneNumber, std::string &secret)
                : 
                index(index), firstName(firstName),
                lastName(lastName), nickname(nickname),
                phoneNumber(phoneNumber), secret(secret){}

Contact::Contact(const Contact &contact)
                :
                index(contact.index), firstName(contact.firstName),
                lastName(contact.lastName), nickname(contact.nickname),
                phoneNumber(contact.phoneNumber), secret(contact.secret){}
Contact::Contact()
                :
                index(0), firstName(""),
                lastName(""), nickname(""),
                phoneNumber(""), secret(""){}

Contact::~Contact(){}

//getters
void Contact::setIndex(int index)
{
    this->index = index;
}
void Contact::setFirstName(std::string &firstName)
{
    this->firstName = firstName;
};
void Contact::setLastName(std::string &lastName)
{
    this->lastName = lastName;
};
void Contact::setNickname(std::string &nickname)
{
    this->nickname = nickname;
};
void Contact::setPhoneNumber(std::string &phoneNumber)
{
    this->phoneNumber = phoneNumber;
};
void Contact::setSecret(std::string &secret)
{
    this->secret = secret;
};

//setters
int Contact::getIndex() const
{
    return this->index;
}
std::string const &Contact::getFirstName(void) const
{
    return this->firstName;
}
std::string const &Contact::getLastName(void) const
{
    return this->lastName;
}
std::string const &Contact::getNickname(void) const
{
    return this->nickname;
}
std::string const &Contact::getPhoneNumber(void) const
{
    return this->phoneNumber;
}
std::string const &Contact::getSecret(void) const
{
    return this->secret;
}

//operators overload
Contact& Contact::operator=(const Contact &contact)
{
    if(this == &contact) return *this;

    this->index = contact.index;
	this->firstName = contact.firstName;
	this->lastName = contact.lastName;
	this->nickname = contact.nickname;
	this->phoneNumber = contact.phoneNumber;
	this->secret = contact.secret;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Contact &c)
{
    os << std::endl;
	os << "** First name:     " << c.getFirstName()   << std::endl;
	os << "** Last name:      " << c.getLastName()    << std::endl;
	os << "** Nickname:       " << c.getNickname()    << std::endl;
	os << "** Phone number:   " << c.getPhoneNumber() << std::endl;
	os << "** Darkest secret: " << c.getSecret()      << std::endl;
    return os;
}
