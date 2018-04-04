#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>

class ScavTrap
{
public:
  ScavTrap(void);
  ScavTrap(std::string name);
  ScavTrap(ScavTrap const &src);
  ~ScavTrap(void);

  int rangedAttack(std::string const &target);
  int meleeAttack(std::string const &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void challengeNewcomer(void);

  int getHintPoints(void) const;
  int getMaxHintPoints(void) const;
  int getEnergyPoints(void) const;
  int getMaxEnergyPoints(void) const;
  int getLevel(void) const;
  std::string getName(void) const;
  int getMeleeAttackDamage(void) const;
  int getRangeAttackdamage(void) const;
  int getArmorDamageReduction(void) const;

  void setHintPoints(int hintPoints);
  void setMaxHintPoints(int maxHintPoints);
  void setEnergyPoints(int energyPoints);
  void setMaxEnergyPoints(int maxEnergyPoints);
  void setLevel(int level);
  void setName(std::string name);
  void setMeleeAttackDamage(int meleeAttackDamage);
  void setRangeAttackdamage(int rangedAttackDamage);
  void setArmorDamageReduction(int armorDamageReduction);

  ScavTrap &operator=(ScavTrap const &rhs);

private:
  std::string _name;
  int _hintPoints;
  int _maxHintPoints;
  int _energyPoints;
  int _maxEnergyPoints;
  int _level;
  int _meleeAttackDamage;
  int _rangedAttackDamage;
  int _armorDamageReduction;
};

#endif //SCAVTRAP_HPP
