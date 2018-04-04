#include <ctime>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : Form("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
{
    *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

bool RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->isSigned() || this->getGradeExecut() < executor.getGrade())
        return false;

    std::cout << "Drilling noises" << std::endl;
    std::srand(std::time(NULL));
    if (std::rand() % 100 >= 50)
        std::cout << this->_target << " has been robotomized successfully" << std::endl;
    else
    {
        std::cout << this->_target << " has not been robotomized" << std::endl;
        return false;
    }
    return true;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
    (void)rhs;
    return *this;
}
