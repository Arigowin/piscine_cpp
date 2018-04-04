#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
}

ClapTrap::ClapTrap(std::string name,
                   int maxHintPoints,
                   int maxEnergyPoints,
                   int meleeAttackDamage,
                   int rangedAttackDamage,
                   int armorDamageReduction) : _name(name),
                                               _maxHintPoints(maxHintPoints),
                                               _maxEnergyPoints(maxEnergyPoints),
                                               _level(1),
                                               _meleeAttackDamage(meleeAttackDamage),
                                               _rangedAttackDamage(rangedAttackDamage),
                                               _armorDamageReduction(armorDamageReduction)
{
    this->_hintPoints = this->_maxHintPoints;
    this->_energyPoints = this->_maxEnergyPoints;

    std::cout << "Building ClapTrap " << this->_name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
    *this = src;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Exterminate ClapTrap " << this->_name << std::endl;
}

int ClapTrap::rangedAttack(void)
{
    return this->_rangedAttackDamage;
}

int ClapTrap::meleeAttack(void)
{
    return this->_meleeAttackDamage;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->_hintPoints -= (amount - this->_armorDamageReduction);
    if (this->_hintPoints < 0)
    {
        this->_hintPoints = 0;
        std::cout << "I don't want to die !!!!!!!! HP: " << this->_hintPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    this->_hintPoints += amount;
    if (this->_hintPoints > this->_maxHintPoints)
        this->_hintPoints = this->_maxHintPoints;
}

int ClapTrap::myRandom(int range)
{
    std::srand(time(0));
    return random() % (range);
}

int ClapTrap::getHintPoints(void) const
{
    return this->_hintPoints;
}

int ClapTrap::getMaxHintPoints(void) const
{
    return this->_maxHintPoints;
}

int ClapTrap::getEnergyPoints(void) const
{
    return this->_energyPoints;
}

int ClapTrap::getMaxEnergyPoints(void) const
{
    return this->_maxEnergyPoints;
}

int ClapTrap::getLevel(void) const
{
    return this->_level;
}

std::string ClapTrap::getName(void) const
{
    return this->_name;
}

int ClapTrap::getMeleeAttackDamage(void) const
{
    return this->_meleeAttackDamage;
}

int ClapTrap::getRangeAttackdamage(void) const
{
    return this->_rangedAttackDamage;
}

int ClapTrap::getArmorDamageReduction(void) const
{
    return this->_armorDamageReduction;
}

void ClapTrap::setHintPoints(int hintPoints)
{
    this->_hintPoints = hintPoints;
}

void ClapTrap::setMaxHintPoints(int maxHintPoints)
{
    this->_maxHintPoints = maxHintPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
    this->_energyPoints = energyPoints;
}

void ClapTrap::setMaxEnergyPoints(int maxEnergyPoints)
{
    this->_maxEnergyPoints = maxEnergyPoints;
}

void ClapTrap::setLevel(int level)
{
    this->_level = level;
}

void ClapTrap::setName(std::string name)
{
    this->_name = name;
}

void ClapTrap::setMeleeAttackDamage(int meleeAttackDamage)
{
    this->_meleeAttackDamage = meleeAttackDamage;
}

void ClapTrap::setRangeAttackdamage(int rangedAttackDamage)
{
    this->_rangedAttackDamage = rangedAttackDamage;
}

void ClapTrap::setArmorDamageReduction(int armorDamageReduction)
{
    this->_armorDamageReduction = armorDamageReduction;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
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
    std::cout << "Things are about to get awesome!" << std::endl;

    return *this;
}
