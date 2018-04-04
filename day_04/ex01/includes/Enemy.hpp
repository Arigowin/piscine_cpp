#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>

class Enemy
{
  public:
    Enemy(void);
    Enemy(int hp, std::string const & type);
    Enemy(Enemy const &src);
    virtual ~Enemy(void);

    int getHP() const;
    std::string const getType(void) const;

    virtual void takeDamage(int dmg);

    Enemy &operator=(Enemy const &rhs);

  protected:
    int _hp;
    std::string _type;
};

#endif //ENEMY_HPP
