#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <iostream>
#include "Victim.hpp"

class Sorcerer
{
  public:
    Sorcerer(std::string name, std::string title);
    Sorcerer(Sorcerer const &src);
    ~Sorcerer(void);

    void polymorph(Victim const &victim) const;

    std::string getName(void) const;
    std::string getTitle(void) const;

    Sorcerer &operator=(Sorcerer const &rhs);

  private:
    Sorcerer(void);

    std::string _name;
    std::string _title;
};

std::ostream &operator<<(std::ostream &out, Sorcerer const &rhs);

#endif //SORCERER_HPP
