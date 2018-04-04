#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"

class Intern
{
  private:
  public:
    Intern(void);
    Intern(Intern const &src);
    ~Intern(void);

    Form *makeForm(std::string formName, std::string target);

    Intern &operator=(Intern const &rhs);
};

#endif //INTERN_HPP
