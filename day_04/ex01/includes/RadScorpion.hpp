#ifndef RADSCORPION_HPP
#define RADSCORPION_HPP

#include "Enemy.hpp"

class RadScorpion : public Enemy
{
  public:
    RadScorpion(void);
    RadScorpion(RadScorpion const &src);
    ~RadScorpion(void);

    RadScorpion &operator=(RadScorpion const &rhs);
};

#endif //RADSCORPION_HPP
