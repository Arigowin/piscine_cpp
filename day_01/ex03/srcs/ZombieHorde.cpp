#include <iostream>
#include "ZombieHorde.hpp"
#include "ZombieEvent.hpp"
#include "Zombie.hpp"

ZombieHorde::ZombieHorde(int n)
{
    ZombieEvent event;
    this->nbZombie = n;
    this->horde = new Zombie[n];

    for (int i = 0; i < n; ++i)
        event.randomChump(&this->horde[i]);
}

ZombieHorde::~ZombieHorde()
{
    delete[] this->horde;
}

void ZombieHorde::announce() const
{
    for (int i = 0; i < this->nbZombie; ++i)
        this->horde[i].announce();
}
