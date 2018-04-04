#include "ACharacter.hpp"

ACharacter::ACharacter(void) : AEntity() {}

ACharacter::ACharacter(size_t posX, size_t posY, size_t sizeX, size_t sizeY, std::string symb, std::string type) : AEntity(posX, posY, sizeX, sizeY, symb, type) {}

ACharacter::ACharacter(ACharacter const &src) {
    *this = src;
}

ACharacter::~ACharacter(void) {}

Shoot ACharacter::shoot(size_t dir, size_t posX, size_t posY, std::string name, std::string symb)
{
    Shoot s(dir, posX + 1, posY, 1, 1, symb, name);

    s.displayShape(symb);
    return s;
}

ACharacter &ACharacter::operator=(ACharacter const &rhs) {
    this->_shape = rhs.getShape();
    this->_posX = rhs.getPosX();
    this->_posY = rhs.getPosY();
    this->_sizeX = rhs.getSizeX();
    this->_sizeY = rhs.getSizeY();
    this->_type = rhs.getType();
    this->_symbole = rhs.getSymbole();    
    return *this;
}
