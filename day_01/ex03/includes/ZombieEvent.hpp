#ifndef ZOMBIE_EVENT_HPP
#define ZOMBIE_EVENT_HPP

#include <iostream>
#include "Zombie.hpp"

class ZombieEvent
{
public:
  ZombieEvent();
  ~ZombieEvent();

  void setZombieType(Zombie *zombie, Zombie::Type type);
  Zombie *newZombie(std::string name);
  void randomChump(Zombie *z);

private:
  std::string _randomString(size_t length);
  Zombie::Type _randomType();
};

#endif // ZOMBIE_EVENT_HPP
