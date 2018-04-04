#include "Shoot.hpp"

Shoot::Shoot(void) : AEntity() {}

Shoot::Shoot(size_t dir, size_t posX, size_t posY, size_t sizeX, size_t sizeY, std::string symbole, std::string type) : AEntity(posX, posY, sizeX, sizeY, symbole, type), _dir(dir) {
}

Shoot::Shoot(Shoot const &src) {
    *this = src;
}

Shoot::~Shoot(void){
    displayShape(" ");
}

void        Shoot::move(size_t dir) {
        AEntity::move(dir);
}

bool        Shoot::move(void) {
    size_t x = 0;
    size_t y = 0;
    getmaxyx(stdscr, y, x);

    if ((this->_dir == KEY_UP && this->_posY > 3) || (this->_dir == KEY_DOWN && this->_posY < y - 1 - this->_sizeY)) {
        this->move(this->_dir);
        return true;
    }
    else
        return false;
}

size_t      Shoot::getDir(void) const {
    return this->_dir;
}

void        Shoot::setDir(size_t dir) {
    this->_dir = dir;
}

void        Shoot::displayShoot(void) const {
    std::cout << AEntity::getType() << std::endl;
}

Shoot       &Shoot::operator=(Shoot const &rhs) {
    this->_shape = rhs.getShape();
    this->_posX = rhs.getPosX();
    this->_posY = rhs.getPosY();
    this->_sizeX = rhs.getSizeX();
    this->_sizeY = rhs.getSizeY();
    this->_type = rhs.getType();
    this->_symbole = rhs.getSymbole();
    this->_dir = rhs.getDir();
    return *this;
}
