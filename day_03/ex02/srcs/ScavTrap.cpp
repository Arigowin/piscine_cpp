#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Nobody", 100, 50, 20, 15, 3)
{
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20, 15, 3)
{
    std::cout << this->_name << ": Hey everybody! Check out my package!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
    *this = src;
    std::cout << this->_name << ": Recompiling my combat code!" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << this->_name << ": STAIRS!? NOOOOOOOOOOOOO!" << std::endl;
}

int ScavTrap::rangedAttack(std::string const &target)
{
    int i = ClapTrap::rangedAttack();
    std::cout << "SC4G-TP " << this->_name << " attacks " << target << " at range, causing " << this->_rangedAttackDamage << " points of damage" << std::endl;
    return i;
}

int ScavTrap::meleeAttack(std::string const &target)
{
    int i = ClapTrap::meleeAttack();
    std::cout << "SC4G-TP " << this->_name << " attacks " << target << " at melee, causing " << this->_meleeAttackDamage << " points of damage" << std::endl;
    return i;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    ClapTrap::takeDamage(amount);
    std::cout << this->_name << ": Why do I even feel pain?! HP: " << this->_hintPoints << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    ClapTrap::beRepaired(amount);
    std::cout << this->_name << ": I found health! HP: " << this->_hintPoints << std::endl;
}

void ScavTrap::challengeNewcomer(void)
{
    std::string challenge[5] = {"Handsome Jack", "The Annihilator", "Bossanova", "August", "STAIRS!?"};
    std::srand(time(0));
    int index = random() % (5);

    if (this->_energyPoints - 25 < 0)
    {
        std::cout << "I need tiny death pellets !" << std::endl;
        return;
    }
    this->_energyPoints -= 25;
    std::cout << challenge[index] << " come to kill you !" << std::endl;
}
