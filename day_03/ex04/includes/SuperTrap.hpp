#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
public:
  SuperTrap(void);
  SuperTrap(std::string name);
  SuperTrap(SuperTrap const &src);
  ~SuperTrap(void);

  using FragTrap::rangedAttack;
  using NinjaTrap::meleeAttack;

  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

private:
  std::string _name;
  int _level;

  using FragTrap::_armorDamageReduction;
  using FragTrap::_hintPoints;
  using FragTrap::_maxHintPoints;
  using FragTrap::_rangedAttackDamage;

  using NinjaTrap::_energyPoints;
  using NinjaTrap::_maxEnergyPoints;
  using NinjaTrap::_meleeAttackDamage;
};

#endif //SUPERTRAP_HPP
