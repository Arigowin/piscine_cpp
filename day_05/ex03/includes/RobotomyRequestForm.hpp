#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
  std::string _target;

public:
  RobotomyRequestForm(void);
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(RobotomyRequestForm const &src);
  ~RobotomyRequestForm(void);

  virtual bool execute(Bureaucrat const &executor) const;

  RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
};

#endif //ROBOTOMYREQUESTFORM
