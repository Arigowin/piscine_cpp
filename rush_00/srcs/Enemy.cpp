#include "Enemy.hpp"

Enemy::Enemy(void) : ACharacter(5, 5, 1, 1, "V", "Enemy") {}

Enemy::Enemy(size_t posX, size_t posY) : ACharacter(posX, posY, rand() % 5, rand() % 5, "V", "Enemy") {}

Enemy::Enemy(Enemy const &src) {
    *this = src;
}

Enemy::~Enemy(void) {
    displayShape(" ");
}

Shoot Enemy::shoot(size_t dir, size_t posX, size_t posY, std::string name, std::string symb) {
    return ACharacter::shoot(dir, posX, posY, name, symb);
}

Shoot Enemy::shoot(void) {
    return this->shoot(KEY_DOWN, this->_posX - 1, this->_posY + this->_sizeY, "EnemyShoot", "*");
}

void        Enemy::move(size_t dir) {
        AEntity::move(dir);
}

bool        Enemy::move(void) {
    size_t  x = 0;
    size_t  y = 0;

    getmaxyx(stdscr, y, x);
    if (this->_posY < y - 1 - this->_sizeY) {
        this->move(KEY_DOWN);
        return true;
    }
    else
        return false;
}

Enemy       &Enemy::operator=(Enemy const &rhs) {
    this->_shape = rhs.getShape();
    this->_posX = rhs.getPosX();
    this->_posY = rhs.getPosY();
    this->_sizeX = rhs.getSizeX();
    this->_sizeY = rhs.getSizeY();
    this->_type = rhs.getType();
    this->_symbole = rhs.getSymbole();    
    return *this;
}
