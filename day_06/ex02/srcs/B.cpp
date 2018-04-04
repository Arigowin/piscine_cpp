#include "B.hpp"

B::B(void) : Base() {}

B::B(B const &src)
{
    *this = src;
}

B::~B() {}

B &B::operator=(B const &rhs)
{
    (void)rhs;
    return *this;
}
