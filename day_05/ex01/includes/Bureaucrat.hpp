#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
  private:
    std::string const _name;
    int _grade;

  public:
    Bureaucrat(void);
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const &src);
    ~Bureaucrat(void);

    void incGrade(void);
    void decGrade(void);
    void signForm(bool sign, std::string formName, std::string reason);

    std::string const getName(void) const;
    int getGrade(void) const;

    Bureaucrat &operator=(Bureaucrat const &rhs);

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

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &bureaucrat);

#endif //BUREAUCRAT_HPP
