#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
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
};

#endif //SCAVTRAP_HPP
