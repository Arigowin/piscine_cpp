#include <iostream>
#include "Enemy.hpp"
#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const &src)
{
    *this = src;
    std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh ..." << std::endl;
}

void SuperMutant::takeDamage(int dmg)
{
    Enemy::takeDamage(dmg - 3);
}

SuperMutant &SuperMutant::operator=(SuperMutant const &rhs)
{
    this->_hp = rhs.getHP();
    this->_type = rhs.getType();
    return *this;
}
