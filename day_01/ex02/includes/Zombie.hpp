#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
public:
  Zombie(std::string name);
  ~Zombie();

  enum Type
  {
    CRAZY,
    LAZY,
    SMART
  };

  Type type;
  std::string name;

  void announce(void) const;
};

#endif // ZOMBIE_HPP
