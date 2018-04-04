#include "ZombieHorde.hpp"

int main(void)
{
    ZombieHorde horde = ZombieHorde(10);

    std::cout << "Number of zombie in the horde: " << horde.nbZombie << std::endl;
    horde.announce();

    return 0;
}
