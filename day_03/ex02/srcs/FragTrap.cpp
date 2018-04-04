#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Nobody", 100, 50, 20, 15, 3)
{
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30, 20, 5)
{
    std::cout << this->_name << ": Look out everybody! Things are about to get awesome!" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
    *this = src;
    std::cout << this->_name << ": Recompiling my combat code!" << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << this->_name << ": It's really quiet... and lonely... (hums briefly) Also this 'stopped moving' thing makes me uncomfortable. It gives me time to stop and think... literally. I'VE STOPPED, AND I'M THINKING! IT HURTS ME!" << std::endl;
}

int FragTrap::rangedAttack(std::string const &target)
{
    int i = ClapTrap::rangedAttack();
    std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at range, causing " << this->_rangedAttackDamage << " points of damage" << std::endl;
    return i;
}

int FragTrap::meleeAttack(std::string const &target)
{
    int i = ClapTrap::meleeAttack();
    std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at melee, causing " << this->_meleeAttackDamage << " points of damage" << std::endl;
    return i;
}

void FragTrap::takeDamage(unsigned int amount)
{
    ClapTrap::takeDamage(amount);
    std::cout << this->_name << ": My robotic flesh! AAHH! HP: " << this->_hintPoints << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
    ClapTrap::beRepaired(amount);
    std::cout << this->_name << ": Sweet life juice! HP: " << this->_hintPoints << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
    std::string attacks[6] = {"Hot potato!", "Take a chill pill!", "I'm a sexy dinosaur! Rawr!", "Get outta the way!", "Let me try!", "Does this mean I can start dancing? Pleeeeeeaaaaase?"};
    int index = ClapTrap::myRandom(6);

    if (this->_energyPoints - 25 < 0)
    {
        std::cout << "Crap, no more shots left!" << std::endl;
        return;
    }
    this->_energyPoints -= 25;
    std::cout << "FR4G-TP " << this->_name << " attacks " << target << " with '" << attacks[index] << "', causing " << (this->_rangedAttackDamage + (index * 5)) << " points of damage" << std::endl;
}
