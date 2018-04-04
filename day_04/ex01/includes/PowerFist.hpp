
#ifndef POWERFIST_HPP
#define POWERFIST_HPP

#include <iostream>
#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
  PowerFist(void);
  PowerFist(PowerFist const &src);
  ~PowerFist(void);

  virtual void attack() const;

  PowerFist &operator=(PowerFist const &rhs);
};

#endif //POWERFIST_HPP
