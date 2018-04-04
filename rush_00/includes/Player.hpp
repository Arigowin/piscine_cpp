#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "ACharacter.hpp"

class Player : public ACharacter
{
  private:
    virtual Shoot   shoot(size_t dir, size_t posX, size_t posY, std::string name, std::string symb);

  public:
    Player(void);
    Player(Player const &src);
    ~Player(void);

    Shoot           shoot(void);

    Player &operator=(Player const &rhs);
};

#endif //PLAYER_HPP
