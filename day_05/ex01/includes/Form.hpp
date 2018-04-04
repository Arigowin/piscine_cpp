#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
  private:
    std::string const _name;
    int const _gradeSign;
    int const _gradeExecut;
    bool _signed;

  public:
    Form(void);
    Form(std::string name, int gradeSign, int gradeExecut);
    Form(Form const &src);
    ~Form(void);

    bool beSign(Bureaucrat &b);

    std::string getName(void) const;
    int getGradeSign(void) const;
    int getGradeExecut(void) const;
    bool isSigned(void) const;

    Form &operator=(Form const &rhs);

    class GradeTooHighException : public std::exception
    {
      public:
        GradeTooHighException(void) throw();
        GradeTooHighException(GradeTooHighException const &src) throw();
        ~GradeTooHighException(void) throw();

        virtual const char *what() const throw();

        GradeTooHighException &operator=(GradeTooHighException const &rhs) throw();
    };
    class GradeTooLowException : public std::exception
    {
      public:
        GradeTooLowException(void) throw();
        GradeTooLowException(GradeTooLowException const &src) throw();
        virtual ~GradeTooLowException(void) throw();

        virtual const char *what() const throw();

        GradeTooLowException &operator=(GradeTooLowException const &rhs) throw();
    };
};

std::ostream &operator<<(std::ostream &stream, const Form &form);

#endif //FORM_HPP
