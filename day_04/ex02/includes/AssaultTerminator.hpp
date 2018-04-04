#ifndef ASSAULTTERMINATOR_HPP
#define ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
  public:
    AssaultTerminator();
    AssaultTerminator(AssaultTerminator const &src);
    virtual ~AssaultTerminator();

    virtual AssaultTerminator *clone() const;
    virtual void battleCry() const;
    virtual void rangedAttack() const;
    virtual void meleeAttack() const;

    AssaultTerminator &operator=(AssaultTerminator const &rhs);
};

#endif //ASSAULTTERMINATOR_HPP
