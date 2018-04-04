#include "ZombieEvent.hpp"
#include "Zombie.hpp"

ZombieEvent::ZombieEvent()
{
}

ZombieEvent::~ZombieEvent()
{
}

void ZombieEvent::setZombieType(Zombie *zombie, Zombie::Type type)
{
    zombie->type = type;
}

Zombie *ZombieEvent::newZombie(std::string name)
{
    Zombie *newZombie = new Zombie(name);
    this->setZombieType(newZombie, Zombie::LAZY);
    return newZombie;
}

void ZombieEvent::randomChump(Zombie *z)
{
    std::string name = this->_randomString(5);
    z->name = name;

    this->setZombieType(z, this->_randomType());
}

Zombie::Type ZombieEvent::_randomType()
{
    int r = random() % 3;
    switch (r)
    {
    case 0:
        return Zombie::CRAZY;
    case 1:
        return Zombie::LAZY;
    case 2:
        return Zombie::SMART;
    }
    return Zombie::LAZY;
}

std::string ZombieEvent::_randomString(size_t length)
{
    std::string str;

    for (size_t i = 0; i < length; i++)
        str += 'a' + random() % 26;

    return str;
}
