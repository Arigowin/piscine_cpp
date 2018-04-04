#include <cstdlib>
#include <iostream>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    Base *ret = NULL;

    int i = rand() % 3;

    if (i == 1)
        ret = dynamic_cast<Base *>(new A());
    else if (i == 2)
        ret = dynamic_cast<Base *>(new B());
    else
        ret = dynamic_cast<Base *>(new C());

    return ret;
}

void identify_from_pointer(Base *p)
{
    try
    {
        A *pA = dynamic_cast<A *>(p);
        if (pA != 0)
            std::cout << "A" << std::endl;
        B *pB = dynamic_cast<B *>(p);
        if (pB != 0)
            std::cout << "B" << std::endl;
        C *pC = dynamic_cast<C *>(p);
        if (pC != 0)
            std::cout << "C" << std::endl;
    }
    catch (const std::bad_cast &e)
    {
        (void)e;
        std::cout << e.what() << std::endl;
    }
}

void identify_from_reference(Base &p)
{
    try
    {
        A &pA = dynamic_cast<A &>(p);
        (void)pA;
        std::cout << "A" << std::endl;
    }
    catch (const std::bad_cast &e)
    {
        (void)e;
    }
    try
    {
        B &pB = dynamic_cast<B &>(p);
        (void)pB;
        std::cout << "B" << std::endl;
    }
    catch (const std::bad_cast &e)
    {
        (void)e;
    }
    try
    {
        C &pC = dynamic_cast<C &>(p);
        (void)pC;
        std::cout << "C" << std::endl;
    }
    catch (const std::bad_cast &e)
    {
        (void)e;
    }
}

int main(void)
{
    Base *a = generate();

    std::cout << "identify_from_pointer" << std::endl;
    identify_from_pointer(a);

    std::cout << "identify_from_reference" << std::endl;
    identify_from_reference(*a);

    return 0;
}

// TYPE& dynamic_cast<TYPE&> (object);
// TYPE* dynamic_cast<TYPE*> (object);
