#include <iostream>
#include "Victim.hpp"

Victim::Victim(void)
{
}

Victim::Victim(std::string name) : _name(name)
{
    std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
}

Victim::Victim(Victim const &src)
{
    *this = src;
    std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
}

Victim::~Victim()
{
    std::cout << "Victim " << this->_name << " just died for no apparent reason !" << std::endl;
}

void Victim::getPolymorphed(void) const
{
    std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
}

std::string Victim::getName(void) const
{
    return this->_name;
}

Victim &Victim::operator=(Victim const &rhs)
{
    this->_name = rhs.getName();
    return *this;
}

std::ostream &operator<<(std::ostream &out, Victim const &rhs)
{
    return out << "I'm " << rhs.getName() << " and I like otters !" << std::endl;
}
