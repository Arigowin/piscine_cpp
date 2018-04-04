#include <iostream>
#include "Sorcerer.hpp"
#include "Victim.hpp"

Sorcerer::Sorcerer(void)
{
}

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{
    std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &src)
{
    *this = src;
    std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same !" << std::endl;
}

void Sorcerer::polymorph(Victim const &victim) const
{
    victim.getPolymorphed();
}

std::string Sorcerer::getName(void) const
{
    return this->_name;
}

std::string Sorcerer::getTitle(void) const
{
    return this->_title;
}

Sorcerer &Sorcerer::operator=(Sorcerer const &rhs)
{
    this->_name = rhs.getName();
    this->_title = rhs.getTitle();
    return *this;
}

std::ostream &operator<<(std::ostream &out, Sorcerer const &rhs)
{
    out << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies !" << std::endl;
    return out;
}
