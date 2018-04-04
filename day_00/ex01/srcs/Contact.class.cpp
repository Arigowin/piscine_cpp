#include <iostream>
#include <iomanip>
#include "Contact.class.hpp"

int Contact::_nbInst = 0;

Contact::Contact()
{}

Contact::~Contact(void)
{
    Contact::_nbInst -= 1;
}

void Contact::addInst(void)
{
    Contact::_nbInst += 1;
}

int Contact::getNbInst(void)
{
    return Contact::_nbInst;
}

void Contact::display(void)
{
    std::cout << "Firstname: " << this->_firstname << std::endl;
    std::cout << "Lastname: " << this->_lastname << std::endl;
    std::cout << "Nickname: " << this->_nickname << std::endl;
    std::cout << "Login: " << this->_login << std::endl;
    std::cout << "Postal address: " << this->_postalAddress << std::endl;
    std::cout << "Email address: " << this->_emailAddress << std::endl;
    std::cout << "Phone number: " << this->_phoneNumber << std::endl;
    std::cout << "Birthday date: " << this->_birthdayDate.tm_mday << "/" << this->_birthdayDate.tm_mon << "/" << this->_birthdayDate.tm_year + 1900 << std::endl;
    std::cout << "Favorite meal: " << this->_favoriteMeal << std::endl;
    std::cout << "Underwear color: " << this->_underwearColor << std::endl;
    std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
}

std::string Contact::getFirstName(void) const
{
    return this->_firstname;
}

std::string Contact::getLastName(void) const
{
    return this->_lastname;
}

std::string Contact::getNickname(void) const
{
    return this->_nickname;
}

std::string Contact::getLogin(void) const
{
    return this->_login;
}

std::string Contact::getPostalAddress(void) const
{
    return this->_postalAddress;
}

std::string Contact::getEmailAddress(void) const
{
    return this->_emailAddress;
}

std::string Contact::getPhoneNumber(void) const
{
    return this->_phoneNumber;
}

struct std::tm Contact::getBirthdayDate(void) const
{
    return this->_birthdayDate;
}

std::string Contact::getFavoriteMeal(void) const
{
    return this->_favoriteMeal;
}

std::string Contact::getUnderwearColor(void) const
{
    return this->_underwearColor;
}

std::string Contact::getDarkestSecret(void) const
{
    return this->_darkestSecret;
}

void Contact::setFirstName(void)
{
    std::cout << "Firstname: ";
    std::cin >> this->_firstname;
}

void Contact::setLastName(void)
{
    std::cout << "Lastname: ";
    std::cin >> this->_lastname;
}

void Contact::setNickname(void)
{
    std::cout << "Nickname: ";
    std::cin >> this->_nickname;
}

void Contact::setLogin(void)
{
    std::cout << "Login: ";
    std::cin >> this->_login;
}

void Contact::setPostalAddress(void)
{
    std::cout << "postal address: ";
    std::cin >> this->_postalAddress;
}

void Contact::setEmailAddress(void)
{
    std::cout << "Email address: ";
    std::cin >> this->_emailAddress;
}

void Contact::setPhoneNumber(void)
{
    std::cout << "Phone number: ";
    std::cin >> this->_phoneNumber;
}

void Contact::setBirthdayDate(void)
{
    bool ok = false;

    while (!ok)
    {
        std::cout << "Birthday date (dd/mm/yyyy): ";
        std::cin >> std::get_time(&this->_birthdayDate, "%d/%m/%Y");

        if (std::cin.fail())
        {
            std::cout << "ERROR: Reading error. please try again!\n";
            std::cin.clear();
            std::cin.ignore();
        }
        else
            ok = true;
    }
}

void Contact::setFavoriteMeal(void)
{
    std::cout << "Favorite meal: ";
    std::cin >> this->_favoriteMeal;
}

void Contact::setUnderwearColor(void)
{
    std::cout << "Underwear color: ";
    std::cin >> this->_underwearColor;
}

void Contact::setDarkestSecret(void)
{
    std::cout << "Darkest secret: ";
    std::cin >> this->_darkestSecret;
}
