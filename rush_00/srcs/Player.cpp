#include "Player.hpp"

Player::Player(void) : ACharacter(1, 1, 1, 1, "A", "Player") {
    size_t  x = 0;
    size_t  y = 0;

    getmaxyx(stdscr, y, x);
    this->displayShape(" ");

    this->_posX = (x / 2) - (this->_sizeX / 2);
    this->_posY = y - this->_sizeY - 1;

    this->displayShape(this->_symbole);
}

Player::Player(Player const &src) {
    *this = src;
}

Player::~Player(void) {
    displayShape(" ");
}

Shoot   Player::shoot(size_t dir, size_t posX, size_t posY, std::string name, std::string symb) {
    return ACharacter::shoot(dir, posX, posY, name, symb);
}

Shoot   Player::shoot(void) {
    return this->shoot(KEY_UP, this->_posX + (this->_sizeX / 2) - 1, this->_posY - 1, "PlayerShoot", "|");
}

Player &Player::operator=(Player const &rhs) {
    this->_shape = rhs.getShape();
    this->_posX = rhs.getPosX();
    this->_posY = rhs.getPosY();
    this->_sizeX = rhs.getSizeX();
    this->_sizeY = rhs.getSizeY();
    this->_type = rhs.getType();
    this->_symbole = rhs.getSymbole();    
    return *this;
}
