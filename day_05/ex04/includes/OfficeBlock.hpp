#ifndef OFFICEBLOCK_HPP
#define OFFICEBLOCK_HPP

#include "Intern.hpp"
#include "Bureaucrat.hpp"

class OfficeBlock
{
  private:
    OfficeBlock(OfficeBlock const &src);
    OfficeBlock &operator=(OfficeBlock const &rhs);

    Intern _intern;
    Bureaucrat _signer;
    Bureaucrat _executor;

  public:
    OfficeBlock(void);
    OfficeBlock(Intern &intern, Bureaucrat &signer, Bureaucrat &executor);
    ~OfficeBlock(void);

    void doBureaucracy(std::string name, std::string target);

    Intern getIntern(void) const;
    Bureaucrat getSigner(void) const;
    Bureaucrat getExecutor(void) const;

    void setIntern(Intern intern);
    void setSigner(Bureaucrat signer);
    void setExecutor(Bureaucrat executor);
};

#endif //OFFICEBLOCK_HPP
