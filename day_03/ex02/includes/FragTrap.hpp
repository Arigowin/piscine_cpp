#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
  FragTrap(void);
  FragTrap(std::string name);
  FragTrap(FragTrap const &src);
  ~FragTrap(void);

  int rangedAttack(std::string const &target);
  int meleeAttack(std::string const &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void vaulthunter_dot_exe(std::string const &target);
};

#endif //FRAGTRAP_HPP
