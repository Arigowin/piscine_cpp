#include <iostream>
#include "Enemy.hpp"

Enemy::Enemy(void)
{
}

Enemy::Enemy(int hp, std::string const &type) : _hp(hp), _type(type)
{
}

Enemy::Enemy(Enemy const &src)
{
    *this = src;
}

Enemy::~Enemy()
{
}

int Enemy::getHP(void) const
{
    return this->_hp;
}

std::string const Enemy::getType(void) const
{
    return this->_type;
}

void Enemy::takeDamage(int dmg)
{
    if (dmg < 0)
        return;
    this->_hp -= dmg;
    if (this->_hp < 0)
        this->_hp = 0;
}

Enemy &Enemy::operator=(Enemy const &rhs)
{
    this->_hp = rhs.getHP();
    this->_type = rhs.getType();
    return *this;
}
