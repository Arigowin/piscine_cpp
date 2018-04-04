#include <iostream>
#include <locale>
#include <string>

int main(int ac, char **av)
{
    std::locale loc;
    std::string str;

    if (ac > 1)
    {
        std::locale loc;
        for (int i = 1; i < ac; ++i)
        {
            str = av[i];
            for (std::string::size_type j = 0; j < str.length(); ++j)
                std::cout << std::toupper(av[i][j], loc);
        }
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;

    return 0;
}
