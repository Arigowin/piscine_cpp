#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <iostream>
#include "Brain.hpp"

class Human
{
  public:
    Human();
    ~Human();

    const Brain brain;

    std::string identify() const;
    Brain const &getBrain() const;
};

#endif //HUMAN_HP
