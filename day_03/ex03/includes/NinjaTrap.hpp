#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
public:
  NinjaTrap(void);
  NinjaTrap(std::string name);
  NinjaTrap(NinjaTrap const &src);
  ~NinjaTrap(void);

  int rangedAttack(std::string const &target);
  int meleeAttack(std::string const &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  void ninjaShoebox(FragTrap &fragTrap);
  void ninjaShoebox(ScavTrap &fragTrap);
  void ninjaShoebox(NinjaTrap &fragTrap);

  // ninjaShoebox
};

#endif //NINJATRAP_HPP
