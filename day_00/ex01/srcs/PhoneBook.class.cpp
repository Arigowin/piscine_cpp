#include <iostream>
#include <iomanip>
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{}

PhoneBook::~PhoneBook(void)
{}

void PhoneBook::add(void)
{
    int nb = Contact::getNbInst();
    if (nb >= 8)
    {
        std::cout << "Maximum contact reached. Cannot add new ones !" << std::endl;
        return;
    }

    contact[nb].setFirstName();
    contact[nb].setLastName();
    contact[nb].setNickname();
    contact[nb].setLogin();
    contact[nb].setPostalAddress();
    contact[nb].setEmailAddress();
    contact[nb].setPhoneNumber();
    contact[nb].setBirthdayDate();
    contact[nb].setFavoriteMeal();
    contact[nb].setUnderwearColor();
    contact[nb].setDarkestSecret();
    contact[nb].addInst();
}

void PhoneBook::search(void)
{
    bool ok = false;
    int rlt = 0;

    if (Contact::getNbInst() <= 0)
    {
        std::cout << "You have no contact !" << std::endl;
        return;
    }

    this->_shortDisplayContacts();

    while (!ok)
    {
        std::cout << "For which contact would you like more information ? [1-" << Contact::getNbInst() << "]: ";
        std::cin >> rlt;

        if (rlt > 0 && rlt <= Contact::getNbInst())
        {
            this->contact[rlt - 1].display();
            ok = true;
        }
        else
        {
            std::cout << "This number is not in range of [1-" << Contact::getNbInst() << "]" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
    }
}

void PhoneBook::_shortDisplayContacts(void)
{
    std::cout << "|  index   |first name|last name | nickname |" << std::endl;
    for (int i = 0; i < Contact::getNbInst(); ++i)
    {
        std::cout << '|';
        std::cout.width(10);
        std::cout << std::right << i + 1;
        std::cout << '|';
        this->_formatString(this->contact[i].getFirstName());
        std::cout << '|';
        this->_formatString(this->contact[i].getLastName());
        std::cout << '|';
        this->_formatString(this->contact[i].getNickname());
        std::cout << '|' << std::endl;
    }
}

void PhoneBook::_formatString(std::string str)
{
    if (str.length() > 10)
        std::cout << str.substr(0, 9) + '.';
    else
    {
        std::cout.width(10);
        std::cout << std::right << str;
    }
}
