#ifndef TACTICALMARINE_HPP
#define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
public:
  TacticalMarine();
  TacticalMarine(TacticalMarine const &src);
  virtual ~TacticalMarine();

  virtual TacticalMarine *clone() const;
  virtual void battleCry() const;
  virtual void rangedAttack() const;
  virtual void meleeAttack() const;

  TacticalMarine &operator=(TacticalMarine const &rhs);
};

#endif //TACTICALMARINE_HP
