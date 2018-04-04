#include "AEntity.hpp"

AEntity::AEntity(void) {}

AEntity::AEntity(size_t posX, size_t posY, size_t sizeX, size_t sizeY, std::string symbole, std::string type) : _posX(posX), _posY(posY), _sizeX(sizeX), _sizeY(sizeY),
                    _symbole(symbole), _type(type) {
    displayShape(symbole);
}

AEntity::AEntity(AEntity const &src) {
    *this = src;
}

AEntity::~AEntity(void) {}

AEntity         &AEntity::operator=(AEntity const &rhs) {
    this->_shape = rhs.getShape();
    this->_posX = rhs.getPosX();
    this->_posY = rhs.getPosY();
    this->_sizeX = rhs.getSizeX();
    this->_sizeY = rhs.getSizeY();
    this->_type = rhs.getType();
    this->_symbole = rhs.getSymbole();
    return *this;
}

void            AEntity::move(size_t key) {
    size_t  x = 0;
    size_t  y = 0;

    getmaxyx(stdscr, y, x);
    displayShape(" ");
    if (key == KEY_UP && this->_posY > 3) {
        this->_posY--;
    }
    if (key == KEY_DOWN && this->_posY < y - 1 - this->_sizeY) {
        this->_posY++;
    }
    if (key == KEY_RIGHT && this->_posX < x - 1 - this->_sizeX) {
        this->_posX++;
    }
    if (key == KEY_LEFT && this->_posX > 1) {
        this->_posX--;
    }
    displayShape(this->_symbole);
}

void     AEntity::displayShape(std::string c) {
    for (size_t y = 0; y < this->_sizeY; y++) {
        for (size_t x = 0; x < this->_sizeX; x++) {
            mvprintw(this->_posY + y, this->_posX + x, c.c_str());
        }
    }
    refresh();
}

std::string     AEntity::getShape(void) const {
    return this->_shape;
}

size_t          AEntity::getPosX(void) const {
    return this->_posX;
}

size_t          AEntity::getPosY(void) const {
    return this->_posY;
}

size_t          AEntity::getSizeX(void) const {
    return this->_sizeX;
}

size_t          AEntity::getSizeY(void) const {
    return this->_sizeY;
}

std::string            AEntity::getSymbole(void) const {
    return this->_symbole;
}

std::string     AEntity::getType(void) const {
    return this->_type;
}

void            AEntity::setPos(int x, int y) {
    this->_posX = x;
    this->_posY = y;
}

void            AEntity::setSize(int x, int y) {
    this->_sizeX = x;
    this->_sizeY = y;
}

void            AEntity::setSymbole(std::string symbole) {
    this->_symbole = symbole;
}

void            AEntity::setType(std::string type) {
    this->_type = type;
}
