#include <iostream>
#include <cstdlib>
#include <cmath>

#include "ScalarConversion.hpp"

bool isInfinite(const double &value)
{
    double max_value = std::numeric_limits<double>::max();
    double min_value = -max_value;

    return !(min_value <= value && value <= max_value);
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "I need an argument." << std::endl;
        return 1;
    }

    ScalarConversion scalarConversion(av[1]);

    try
    {
        std::cout << "Char: ";
        char c = scalarConversion;
        std::cout << c << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "Int: ";
        int i = scalarConversion;
        std::cout << i << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "Float: ";
        float f = scalarConversion;
        std::cout << f;
        if (f == std::floor(f) && !isInfinite(f))
            std::cout << ".0";
        std::cout << 'f' << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "Double: ";
        double d = scalarConversion;
        std::cout << d;
        if (d == std::floor(d) && !isInfinite(d))
            std::cout << ".0";
        std::cout << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }


    return 0;
}
