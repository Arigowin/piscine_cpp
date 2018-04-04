#include <iostream>
#include "SuperTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

SuperTrap::SuperTrap(void) : ClapTrap(), _name("Nobody"), _level(1)
{
    std::cout << this->_name << ": Look out everybody! Things are about to get awesome!" << std::endl;
}

SuperTrap::SuperTrap(std::string name) : ClapTrap(), _name(name), _level(1)
{
    std::cout << this->_name << ": Look out everybody! Things are about to get awesome!" << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const &src) : ClapTrap(src)
{
    *this = src;
    std::cout << this->_name << ": Recompiling my combat code!" << std::endl;
}

SuperTrap::~SuperTrap(void)
{
    std::cout << this->_name << ": It's really quiet... and lonely... (hums briefly) Also this 'stopped moving' thing makes me uncomfortable. It gives me time to stop and think... literally. I'VE STOPPED, AND I'M THINKING! IT HURTS ME!" << std::endl;
}

void SuperTrap::takeDamage(unsigned int amount)
{
    ClapTrap::takeDamage(amount);
    std::cout << this->_name << ": If only my chassis... weren't made of recycled human body parts! Wahahaha! AAHH! HP: " << this->_hintPoints << std::endl;
}

void SuperTrap::beRepaired(unsigned int amount)
{
    ClapTrap::beRepaired(amount);
    std::cout << this->_name << ": Health! Eww, what flavor is red? HP: " << this->_hintPoints << std::endl;
}
