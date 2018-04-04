#include <iostream>
#include <cstdlib>
#include <ctime>
#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
}

FragTrap::FragTrap(std::string name) : _name(name),
                                       _maxHintPoints(100),
                                       _maxEnergyPoints(100),
                                       _level(1),
                                       _meleeAttackDamage(30),
                                       _rangedAttackDamage(20),
                                       _armorDamageReduction(5)
{
    this->_hintPoints = this->_maxHintPoints;
    this->_energyPoints = this->_maxEnergyPoints;
    std::cout << this->_name << ": Look out everybody! Things are about to get awesome!" << std::endl;
}

FragTrap::FragTrap(FragTrap const &src)
{
    *this = src;
}

FragTrap::~FragTrap()
{
    std::cout << this->_name << ": It's really quiet... and lonely... (hums briefly) Also this 'stopped moving' thing makes me uncomfortable. It gives me time to stop and think... literally. I'VE STOPPED, AND I'M THINKING! IT HURTS ME!" << std::endl;
}

int FragTrap::rangedAttack(std::string const &target)
{
    std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at range, causing " << this->_rangedAttackDamage << " points of damage" << std::endl;
    return this->_rangedAttackDamage;
}

int FragTrap::meleeAttack(std::string const &target)
{
    std::cout << "FR4G-TP " << this->_name << " attacks " << target << " at melee, causing " << this->_meleeAttackDamage << " points of damage" << std::endl;
    return this->_meleeAttackDamage;
}

void FragTrap::takeDamage(unsigned int amount)
{
    this->_hintPoints -= (amount - this->_armorDamageReduction);
    if (this->_hintPoints < 0)
    {
        this->_hintPoints = 0;
        std::cout << this->_name << ": I don't want to die !!!!!!!! HP: " << this->_hintPoints << std::endl;
    }
    else
        std::cout << this->_name << ": My robotic flesh! AAHH! HP: " << this->_hintPoints << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
    this->_hintPoints += amount;
    if (this->_hintPoints > this->_maxHintPoints)
        this->_hintPoints = this->_maxHintPoints;
    std::cout << this->_name << ": Sweet life juice! HP: " << this->_hintPoints << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
    std::string attacks[6] = {"Hot potato!", "Take a chill pill!", "I'm a sexy dinosaur! Rawr!", "Get outta the way!", "Let me try!", "Does this mean I can start dancing? Pleeeeeeaaaaase?"};
    std::srand(time(0));
    int index = random() % (6);

    if (this->_energyPoints - 25 < 0)
    {
        std::cout << "Crap, no more shots left!" << std::endl;
        return;
    }
    this->_energyPoints -= 25;
    std::cout << "FR4G-TP " << this->_name << " attacks " << target << " with '" << attacks[index] << "', causing " << (this->_rangedAttackDamage + (index * 5)) << " points of damage" << std::endl;
}

int FragTrap::getHintPoints(void) const
{
    return this->_hintPoints;
}

int FragTrap::getMaxHintPoints(void) const
{
    return this->_maxHintPoints;
}

int FragTrap::getEnergyPoints(void) const
{
    return this->_energyPoints;
}

int FragTrap::getMaxEnergyPoints(void) const
{
    return this->_maxEnergyPoints;
}

int FragTrap::getLevel(void) const
{
    return this->_level;
}

std::string FragTrap::getName(void) const
{
    return this->_name;
}

int FragTrap::getMeleeAttackDamage(void) const
{
    return this->_meleeAttackDamage;
}

int FragTrap::getRangeAttackdamage(void) const
{
    return this->_rangedAttackDamage;
}

int FragTrap::getArmorDamageReduction(void) const
{
    return this->_armorDamageReduction;
}

void FragTrap::setHintPoints(int hintPoints)
{
    this->_hintPoints = hintPoints;
}

void FragTrap::setMaxHintPoints(int maxHintPoints)
{
    this->_maxHintPoints = maxHintPoints;
}

void FragTrap::setEnergyPoints(int energyPoints)
{
    this->_energyPoints = energyPoints;
}

void FragTrap::setMaxEnergyPoints(int maxEnergyPoints)
{
    this->_maxEnergyPoints = maxEnergyPoints;
}

void FragTrap::setLevel(int level)
{
    this->_level = level;
}

void FragTrap::setName(std::string name)
{
    this->_name = name;
}

void FragTrap::setMeleeAttackDamage(int meleeAttackDamage)
{
    this->_meleeAttackDamage = meleeAttackDamage;
}

void FragTrap::setRangeAttackdamage(int rangedAttackDamage)
{
    this->_rangedAttackDamage = rangedAttackDamage;
}

void FragTrap::setArmorDamageReduction(int armorDamageReduction)
{
    this->_armorDamageReduction = armorDamageReduction;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
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
    std::cout << this->_name << ": Recompiling my combat code!" << std::endl;

    return *this;
}
