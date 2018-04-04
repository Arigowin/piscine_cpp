#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
  private:
    std::string _target;

  public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm const &src);
    ~PresidentialPardonForm(void);

    virtual bool execute(Bureaucrat const &executor) const;

    PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
};

#endif //PRESIDENTIALPARDONFORM_HPP
