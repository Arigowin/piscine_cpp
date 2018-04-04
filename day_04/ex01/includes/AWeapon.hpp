#ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <iostream>

class AWeapon
{
public:
  AWeapon(void);
  AWeapon(std::string const &name, int apcost, int damage);
  AWeapon(AWeapon const &src);
  virtual ~AWeapon(void);

  virtual void attack() const = 0;

  std::string const getName() const;
  int getAPCost() const;
  int getDamage() const;

  AWeapon &operator=(AWeapon const &rhs);

protected:
  std::string _name;
  int _apcost;
  int _damage;
};

#endif //AWEAPON_HPP
