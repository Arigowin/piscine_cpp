#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "ACharacter.hpp"

class Enemy : public ACharacter
{
  private:
    virtual Shoot   shoot(size_t dir, size_t posX, size_t posY, std::string name, std::string symb);
    virtual void    move(size_t dir);

  public:
    Enemy(void);
    Enemy(size_t posX, size_t posY);
    Enemy(Enemy const &src);
    ~Enemy(void);

    Shoot           shoot(void);
    bool            move(void);

    Enemy &operator=(Enemy const &rhs);
};

#endif
