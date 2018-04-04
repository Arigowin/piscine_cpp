#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
    this->type = LAZY;
    std::cout << "A human died, he turns into a zombie !!! His name is " << name << std::endl;
}

Zombie::Zombie()
{
    std::cout << "A human died, he turns into a zombie !!!" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << '<' << this->name << " (";
    switch (this->type)
    {
    case CRAZY:
        std::cout << "CRAZY";
        break;
    case LAZY:
        std::cout << "LAZY";
        break;
    case SMART:
        std::cout << "SMART";
        break;
    }
    std::cout << ")> is crushed by a truck" << std::endl;
}

void Zombie::announce(void) const
{
    std::cout << '<' << this->name << " (";
    switch (this->type)
    {
    case CRAZY:
        std::cout << "CRAZY";
        break;
    case LAZY:
        std::cout << "LAZY";
        break;
    case SMART:
        std::cout << "SMART";
        break;
    }
    std::cout << ")> Braiiiiiiinnnssss..." << std::endl;
}
