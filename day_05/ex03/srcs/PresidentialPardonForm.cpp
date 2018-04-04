#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : Form("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src)
{
    *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

bool PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!this->isSigned() || this->getGradeExecut() < executor.getGrade())
        return false;

    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;

    return true;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
    (void)rhs;
    return *this;
}
