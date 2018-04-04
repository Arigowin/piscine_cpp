#include <iostream>
#include "Array.tpp"

int main(void)
{
    std::cout << "Array<int> a(5)" << std::endl;
    Array<int> a(5);

    std::cout << "Size: " << a.size() << std::endl;

    for (unsigned int i = 0; i < a.size(); ++i)
    {
        int x = a[i];
        std::cout << "i: " << i << " value: " << x << std::endl;
    }
    try
    {
        int x = a[5];
        std::cout << "i: 5 value: " << x << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Array<int> b" << std::endl;
    Array<int> b;

    std::cout << "Size: " << b.size() << std::endl;

    for (unsigned int i = 0; i < b.size(); ++i)
    {
        int x = b[i];
        std::cout << "i: " << i << " value: " << x << std::endl;
    }
    try
    {
        int x = b[0];
        std::cout << "i: 0 value: " << x << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Array<std::string> s(5)" << std::endl;
    Array<std::string> s(5);

    std::cout << "Size: " << s.size() << std::endl;

    for (unsigned int i = 0; i < s.size(); ++i)
    {
        std::string x = s[i];
        std::cout << "i: " << i << " value: [" << x << "]" << std::endl;
    }

    std::cout << "Array<int> cpy(a)" << std::endl;
    Array<int> cpy(a);

    std::cout << "cpy[1] = 6" << std::endl;
    cpy[1] = 6;

    std::cout << "Print a" << std::endl;
    for (unsigned int i = 0; i < a.size(); ++i)
    {
        int x = a[i];
        std::cout << "i: " << i << " value: " << x << std::endl;
    }

    std::cout << "Print cpy" << std::endl;
    for (unsigned int i = 0; i < cpy.size(); ++i)
    {
        int x = cpy[i];
        std::cout << "i: " << i << " value: " << x << std::endl;
    }

    return 0;
}
