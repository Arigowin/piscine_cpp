#include "C.hpp"

C::C(void) : Base() {}

C::C(C const &src)
{
    *this = src;
}

C::~C() {}

C &C::operator=(C const &rhs)
{
    (void)rhs;
    return *this;
}
