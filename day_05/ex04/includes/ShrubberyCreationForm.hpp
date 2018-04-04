#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
  std::string _target;

public:
  ShrubberyCreationForm(void);
  ShrubberyCreationForm(std::string target);
  ShrubberyCreationForm(ShrubberyCreationForm const &src);
  ~ShrubberyCreationForm(void);

  virtual bool execute(Bureaucrat const &executor) const;

  ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
};

#endif //SHRUBBERYCREATIONFORM_HPP
