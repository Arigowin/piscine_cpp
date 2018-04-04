#ifndef ZOMBIEHODE_HPP
#define ZOMBIEHODE_HPP

#include "Zombie.hpp"

class ZombieHorde
{
public:
    ZombieHorde(int n);
    ~ZombieHorde();

    void announce() const;

    int nbZombie;
    Zombie *horde;
};

#endif //ZOMBIEHODE_HPP
