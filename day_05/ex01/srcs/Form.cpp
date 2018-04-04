#include "Form.hpp"

Form::Form(void) : _name(""), _gradeSign(150), _gradeExecut(150), _signed(false) {}

Form::Form(std::string name, int gradeSign, int gradeExecut)
    : _name(name), _gradeSign(gradeSign), _gradeExecut(gradeExecut), _signed(false)
{
    if (gradeSign < 1 || gradeExecut < 1)
        throw Form::GradeTooHighException();
    if (gradeSign > 150 || gradeExecut > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const &src) : _name(""), _gradeSign(150), _gradeExecut(150), _signed(false)
{
    *this = src;
}

Form::~Form() {}

bool Form::beSign(Bureaucrat &b)
{
    if (this->_gradeSign < b.getGrade())
    {
        b.signForm(false, this->_name, "Grade to Low");
        throw Form::GradeTooLowException();
        return false;
    }
    b.signForm(true, this->_name, "");
    this->_signed = true;
    return true;
}

std::string Form::getName(void) const
{
    return this->_name;
}

int Form::getGradeSign(void) const
{
    return this->_gradeSign;
}

int Form::getGradeExecut(void) const
{
    return this->_gradeExecut;
}

bool Form::isSigned(void) const
{
    return this->_signed;
}

Form &Form::operator=(Form const &rhs)
{
    (void)rhs;
    return *this;
}

Form::GradeTooHighException::GradeTooHighException(void) throw() : std::exception() {}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src) throw()
{
    *this = src;
}

Form::GradeTooHighException::~GradeTooHighException(void) throw() {}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

Form::GradeTooHighException &Form::GradeTooHighException::operator=(GradeTooHighException const &rhs) throw()
{
    (void)rhs;
    return *this;
}

Form::GradeTooLowException::GradeTooLowException(void) throw() : std::exception() {}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src) throw()
{
    *this = src;
}

Form::GradeTooLowException::~GradeTooLowException(void) throw() {}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade too loow");
}

Form::GradeTooLowException &Form::GradeTooLowException::operator=(GradeTooLowException const &rhs) throw()
{
    (void)rhs;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << f.getName() << ", grade required to sign " << f.getGradeSign();
    os << ", grade required to execute " << f.getGradeExecut();
    return os;
}
