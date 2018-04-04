#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) {}

Intern::Intern(Intern const &src)
{
    *this = src;
}

Intern::~Intern() {}

Form *Intern::makeForm(std::string formName, std::string target)
{
    Form *form = NULL;

    if (formName == "robotomy request")
        form = new RobotomyRequestForm(target);
    else if (formName == "shrubbery creation")
        form = new ShrubberyCreationForm(target);
    else if (formName == "presidential pardon")
        form = new PresidentialPardonForm(target);
    else
    {
        std::cout << "Intern can't creates request for [" << formName << "]" << std::endl;
        return NULL;
    }

    std::cout << "Intern creates " << *form << std::endl;
    return form;
}

Intern &Intern::operator=(Intern const &rhs)
{
    (void)rhs;
    return *this;
}
