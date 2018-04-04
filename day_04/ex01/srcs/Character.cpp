#include <iostream>
#include "Enemy.hpp"
#include "AWeapon.hpp"
#include "Character.hpp"

Character::Character(void)
{
}

Character::Character(std::string const &name) : _name(name), _ap(40), _weapon(NULL)
{
}

Character::Character(Character const &src)
{
    *this = src;
}

Character::~Character()
{
}

void Character::recoverAP() {
    this->_ap += 10;
    if (this->_ap > 40)
        this->_ap = 40;
}

void Character::equip(AWeapon *weapon) {
    this->_weapon = weapon;
}

void Character::attack(Enemy *enemy) {
    if (this->_weapon == NULL || this->_ap - this->_weapon->getAPCost() < 0)
        return;

    std::cout << this->_name << " attacks " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
    this->_weapon->attack();
    this->_ap -= this->_weapon->getAPCost();
    enemy->takeDamage(this->_weapon->getDamage());
    if (enemy->getHP() <= 0)
        delete enemy;
}

std::string const Character::getName(void) const
{
    return this->_name;
}

int Character::getAP() const {
   return this->_ap;
}

AWeapon *Character::getWeapon() const {
    return this->_weapon;
}

Character &Character::operator=(Character const &rhs) {

    this->_name = rhs.getName();
    this->_ap = rhs.getAP();
    this->_weapon = rhs.getWeapon();
    return *this;
}

std::ostream &operator<<(std::ostream &out, Character const &rhs)
{
    if (rhs.getWeapon())
        out << rhs.getName() << " has " << rhs.getAP() << " AP and wields a " << rhs.getWeapon()->getName() << std::endl;
    else
        out << rhs.getName() << " has " << rhs.getAP() << " AP and is unarmed" << std::endl;
    return out;
}
