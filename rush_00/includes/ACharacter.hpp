#ifndef ACHARACTER_HPP
#define ACHARACTER_HPP

#include "Shoot.hpp"

class ACharacter : public AEntity
{
  protected:
    ACharacter(void);
    ACharacter(size_t posX, size_t posY, size_t sizeX, size_t sizeY, std::string symb, std::string type);
    ACharacter(ACharacter const &src);
    virtual ~ACharacter(void);

    virtual Shoot   shoot(size_t dir, size_t posX, size_t posY, std::string name, std::string symb);

    ACharacter      &operator=(ACharacter const &rhs);
};

#endif
