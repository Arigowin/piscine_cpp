#include "ZombieEvent.hpp"
#include "Zombie.hpp"

int main(void)
{
    ZombieEvent event = ZombieEvent();

    event.randomChump();
    event.randomChump();
    event.randomChump();
    event.randomChump();
    event.randomChump();
    event.randomChump();

    ZombieEvent event2 = ZombieEvent();
    Zombie *gerard = event2.newZombie("Gerard");
    event2.setZombieType(gerard, Zombie::CRAZY);
    gerard->announce();
    delete gerard;

    return 0;
}
