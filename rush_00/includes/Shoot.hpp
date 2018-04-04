#ifndef SHOOT_HPP
#define SHOOT_HPP

#include "AEntity.hpp"

class Shoot : public AEntity
{
  private:
    size_t        _dir;

    virtual void  move(size_t dir);

  public:
    Shoot(void);
    Shoot(size_t dir, size_t posX, size_t posY, size_t sizeX, size_t sizeY, std::string symbole, std::string type);
    Shoot(Shoot const &src);
    ~Shoot(void);

    bool          move(void);

    size_t        getDir(void) const;
    void          setDir(size_t dir);

    void          displayShoot(void) const;

    Shoot         &operator=(Shoot const &rhs);
};

#endif //SHOOT_HPP
