#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "Enemy.hpp"
#include "AWeapon.hpp"

class Character
{
  public:
    Character(void);
    Character(std::string const &name);
    Character(Character const &src);
    ~Character(void);

    void recoverAP();
    void equip(AWeapon *weapon);
    void attack(Enemy *enemy);

    std::string const getName() const;
    int getAP() const;
    AWeapon *getWeapon() const;

    Character &operator=(Character const &rhs);

  private:
    std::string _name;
    int _ap;
    AWeapon *_weapon;
};

std::ostream &operator<<(std::ostream &out, Character const &rhs);

#endif //CHARACTER_HPP
