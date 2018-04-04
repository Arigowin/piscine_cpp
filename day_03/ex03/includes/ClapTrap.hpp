#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
public:
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

  ClapTrap &operator=(ClapTrap const &rhs);

protected:
  ClapTrap(void);
  ClapTrap(std::string name, int maxHintPoints, int maxEnergyPoints, int meleeAttackDamage, int rangedAttackDamage, int armorDamageReduction);
  ClapTrap(ClapTrap const &src);
  ~ClapTrap(void);

  int rangedAttack(void);
  int meleeAttack(void);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  int myRandom(int range);

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

#endif //CLAPTRAP_HPP
