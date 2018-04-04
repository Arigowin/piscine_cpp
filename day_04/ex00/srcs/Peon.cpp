#include <iostream>
#include "Victim.hpp"
#include "Peon.hpp"

Peon::Peon(void)
{
}

Peon::Peon(std::string name) : Victim(name)
{
    std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const &src) : Victim(src)
{
    std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
    std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed(void) const
{
    std::cout << this->_name << " has been turned into a pink pony !" << std::endl;
}

Peon &Peon::operator=(Peon const &rhs)
{
    this->_name = rhs.getName();
    return *this;
}
