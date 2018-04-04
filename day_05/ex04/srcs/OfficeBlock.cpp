#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(OfficeBlock const &src)
{
    *this = src;
}

OfficeBlock &OfficeBlock::operator=(OfficeBlock const &rhs)
{
    (void)rhs;
    return *this;
}

OfficeBlock::OfficeBlock(void) {}

OfficeBlock(Intern &intern, Bureaucrat &signer, Bureaucrat &executor)
    : _intern(intern), _signer(signer), _executor(executor) {}

OfficeBlock::~OfficeBlock() {}

void OfficeBlock::doBureaucracy(std::string name, std::string target)
{
    if (!this->_intern && !this->_signer && !this->_signer)
    {
        return;
    }


}

Intern OfficeBlock::getIntern(void) const
{
    return this->_intern;
}

Bureaucrat OfficeBlock::getSigner(void) const
{
    return this->_signer;
}

Bureaucrat OfficeBlock::getExecutor(void) const
{
    return this->_executor;
}

void OfficeBlock::setIntern(Intern intern)
{
    this->_intern = intern;
}

void OfficeBlock::setSigner(Bureaucrat signer)
{
    this->_signer = signer;
}

void OfficeBlock::setExecutor(Bureaucrat executor)
{
    this->_executor = executor;
}
