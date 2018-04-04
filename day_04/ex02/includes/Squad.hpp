#ifndef SQUAD_HPP
#define SQUAD_HPP

#include "ISpaceMarine.hpp"
#include "ISquad.hpp"

class Squad : public ISquad
{
public:
  Squad(void);
  Squad(Squad const &src);
  virtual ~Squad();

  virtual int push(ISpaceMarine *spaceMarine);

  virtual int getCount() const;
  virtual ISpaceMarine *getUnit(int n) const;

  ISpaceMarine **getSpaceMarines() const;

  Squad &operator=(Squad const &rhs);

private:
  int _nbUnits;
  ISpaceMarine **_spaceMarines;
};

#endif //SQUAD_HPP
