#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {

}

ScavTrap::ScavTrap(std::string name) : _name(name),
                                       _maxHintPoints(100),
                                       _maxEnergyPoints(50),
                                       _level(1),
                                       _meleeAttackDamage(20),
                                       _rangedAttackDamage(15),
                                       _armorDamageReduction(3)
{
    this->_hintPoints = this->_maxHintPoints;
    this->_energyPoints = this->_maxEnergyPoints;
    std::cout << this->_name << ": Hey everybody! Check out my package!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
    *this = src;
}

ScavTrap::~ScavTrap()
{
    std::cout << this->_name << ": STAIRS!? NOOOOOOOOOOOOO!" << std::endl;
}

int ScavTrap::rangedAttack(std::string const &target)
{
    std::cout << "SC4G-TP " << this->_name << " attacks " << target << " at range, causing " << this->_rangedAttackDamage << " points of damage" << std::endl;
    return this->_rangedAttackDamage;
}

int ScavTrap::meleeAttack(std::string const &target)
{
    std::cout << "SC4G-TP " << this->_name << " attacks " << target << " at melee, causing " << this->_meleeAttackDamage << " points of damage" << std::endl;
    return this->_meleeAttackDamage;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    this->_hintPoints -= (amount - this->_armorDamageReduction);
    if (this->_hintPoints < 0)
    {
        this->_hintPoints = 0;
        std::cout << this->_name << ": I don't want to die !!!!!!!! HP: " << this->_hintPoints << std::endl;
    }
    else
        std::cout << this->_name << ": Why do I even feel pain?! HP: " << this->_hintPoints << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    this->_hintPoints += amount;
    if (this->_hintPoints > this->_maxHintPoints)
        this->_hintPoints = this->_maxHintPoints;
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

int ScavTrap::getHintPoints(void) const
{
    return this->_hintPoints;
}

int ScavTrap::getMaxHintPoints(void) const
{
    return this->_maxHintPoints;
}

int ScavTrap::getEnergyPoints(void) const
{
    return this->_energyPoints;
}

int ScavTrap::getMaxEnergyPoints(void) const
{
    return this->_maxEnergyPoints;
}

int ScavTrap::getLevel(void) const
{
    return this->_level;
}

std::string ScavTrap::getName(void) const
{
    return this->_name;
}

int ScavTrap::getMeleeAttackDamage(void) const
{
    return this->_meleeAttackDamage;
}

int ScavTrap::getRangeAttackdamage(void) const
{
    return this->_rangedAttackDamage;
}

int ScavTrap::getArmorDamageReduction(void) const
{
    return this->_armorDamageReduction;
}

void ScavTrap::setHintPoints(int hintPoints)
{
    this->_hintPoints = hintPoints;
}

void ScavTrap::setMaxHintPoints(int maxHintPoints)
{
    this->_maxHintPoints = maxHintPoints;
}

void ScavTrap::setEnergyPoints(int energyPoints)
{
    this->_energyPoints = energyPoints;
}

void ScavTrap::setMaxEnergyPoints(int maxEnergyPoints)
{
    this->_maxEnergyPoints = maxEnergyPoints;
}

void ScavTrap::setLevel(int level)
{
    this->_level = level;
}

void ScavTrap::setName(std::string name)
{
    this->_name = name;
}

void ScavTrap::setMeleeAttackDamage(int meleeAttackDamage)
{
    this->_meleeAttackDamage = meleeAttackDamage;
}

void ScavTrap::setRangeAttackdamage(int rangedAttackDamage)
{
    this->_rangedAttackDamage = rangedAttackDamage;
}

void ScavTrap::setArmorDamageReduction(int armorDamageReduction)
{
    this->_armorDamageReduction = armorDamageReduction;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
    this->_name = rhs.getName();
    this->_hintPoints = rhs.getHintPoints();
    this->_maxHintPoints = rhs.getMaxHintPoints();
    this->_energyPoints = rhs.getEnergyPoints();
    this->_maxEnergyPoints = rhs.getMaxEnergyPoints();
    this->_level = rhs.getLevel();
    this->_meleeAttackDamage = rhs.getMeleeAttackDamage();
    this->_rangedAttackDamage = rhs.getRangeAttackdamage();
    this->_armorDamageReduction = rhs.getArmorDamageReduction();
    std::cout << this->_name << ": Things are about to get awesome!" << std::endl;

    return *this;
}
