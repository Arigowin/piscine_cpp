#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::Bureaucrat(std::string name, int grade)
    : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
    *this = src;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::incGrade(void)
{
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();

    this->_grade--;
}

void Bureaucrat::decGrade(void)
{
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

std::string const Bureaucrat::getName(void) const
{
    return this->_name;
}

int Bureaucrat::getGrade(void) const
{
    return this->_grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    this->_grade = rhs.getGrade();
    return *this;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) throw() : std::exception() {}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src) throw()
{
    *this = src;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const &rhs) throw()
{
    (void)rhs;
    return *this;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) throw() : std::exception() {}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src) throw()
{
    *this = src;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too loow");
}

Bureaucrat::GradeTooLowException &Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const &rhs) throw()
{
    (void)rhs;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
