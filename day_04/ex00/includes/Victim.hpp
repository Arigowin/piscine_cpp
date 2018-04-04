#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <iostream>

class Victim
{
  public:
    Victim(void);
    Victim(std::string name);
    Victim(Victim const &src);
    ~Victim(void);

    virtual void getPolymorphed(void) const;

    std::string getName(void) const;

    Victim &operator=(Victim const &rhs);

  protected:
    std::string _name;
};

std::ostream &operator<<(std::ostream &out, Victim const &rhs);

#endif //VICTIM_HPP
