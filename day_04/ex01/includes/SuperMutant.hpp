#ifndef SUPERMUTANT_HPP
#define SUPERMUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy
{
  public:
    SuperMutant(void);
    SuperMutant(SuperMutant const &src);
    ~SuperMutant(void);

    virtual void takeDamage(int dmg);

    SuperMutant &operator=(SuperMutant const &rhs);
};

#endif //SUPERMUTANT_HPP
