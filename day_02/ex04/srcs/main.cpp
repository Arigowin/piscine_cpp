#include <sstream>
#include <iostream>
#include "Fixed.class.hpp"

std::string rpn(std::string str)
{
    std::istringstream iss(str);

    std::string tmp;
    std::string tmpRpn;
    std::string tmpSymbole;

    while (!iss.eof())
    {
        iss >> tmp;

        if (std::isdigit(tmp[0]))
            tmpRpn += tmp + " ";
        else
        {
            tmpSymbole = tmp + " " + tmpSymbole;
            if (tmpSymbole[0] == ')')
            {
                tmpSymbole.erase(0, 1);
                size_t pos = tmpSymbole.find_first_of('(');
                if (pos == std::string::npos)
                    pos = tmpSymbole.length();
                tmpRpn += tmpSymbole.substr(0, pos);
                tmpSymbole.erase(0, pos + 1);
            }
        }
    }
    tmpRpn += tmpSymbole;

    return tmpRpn;
}

std::string skim(std::string str)
{
    Fixed fixed2;
    int i = 0;
    std::cout << "start skim; [" << str << "]" << std::endl;
    std::cout << "1" << std::endl;
    while (str.find('+') && str.find('-') && str.find('*') && str.find('/'))
    {
        std::cout << "2" << std::endl;

        std::istringstream iss(str);
        iss.seekg(0);

        std::string tmp;
        float tmpF1;
        float tmpF2;
        bool bln = false;
        std::cout << "3" << std::endl;

        if (!iss.eof())
        {
            iss >> tmpF1;
            iss >> tmpF2; // Attention peut etre op
            std::cout << "4" << std::endl;

            Fixed fixed1(tmpF1);
            fixed2.setRawBits(tmpF2);
            std::cout << "5" << std::endl;

            while (iss.peek() == ' ')
                iss.ignore(10, ' ');
            std::cout << "6 [" << iss.peek() << std::endl;

            if (std::isdigit(iss.peek()))
            {
                std::ostringstream oss;
                oss << tmpF2;
                for (size_t i = 0; i < oss.str().length() + 2; ++i)
                    iss.unget();

                std::cout << "PILE"
                          << " iss [" << iss.str().substr(iss.tellg()) << "] tmp1 " << tmpF1 << " tmp2 " << tmpF2 << std::endl;
                str = skim(iss.str().substr(iss.tellg()));
                std::cout << "DEPILE ret = "
                          << " iss [" << str << "] tmp1 " << tmpF1 << " tmp2 " << tmpF2 << std::endl;
                std::istringstream iss2(str);

                iss2 >> tmpF2;
                fixed2.setRawBits(tmpF2);


                str = fixed1.str() + " " + str;
            }
            std::cout << "iss [" << str << "] tmp1 " << tmpF1 << " tmp2 " << tmpF2 << std::endl;

            iss >> tmp;
            std::cout << "7 [" << tmp << "]" << std::endl;
            int l1 = fixed1.str().length();
            int l2 = fixed2.str().length();

            switch (tmp[0])
            {
            case '+':
                fixed2 = fixed2 + fixed1;
                std::cout << "+" << std::endl;

                break;
            case '-':
                fixed2 = fixed1 - fixed2;
                std::cout << "-" << std::endl;

                break;
            case '*':
                fixed2 = fixed2 * fixed1;
                std::cout << "*" << std::endl;

                break;
            case '/':
                fixed2 = fixed1 / fixed2;
                std::cout << "/" << std::endl;

                break;
            }

            std::cout << "8 " << std::endl;

            if (bln == true)
            {
                std::cout << "9 [" << str << "] " << iss.tellg() << std::endl;
                str = fixed1.str() + " " + str;
                std::cout << "9 [" << str << "] " << iss.tellg() << std::endl;
            }
            else
            {
                std::cout << "10 [" << str << "] " << iss.tellg() << std::endl;
                str = fixed2.str() + " " + str.substr(l1 + l2);
                std::cout << "10 [" << str << "] " << iss.tellg() << std::endl;
                return str;
            }

            std::cout << "STR: [" << str << "]" << std::endl;
            // return str;
        }
        i++;
    }
    return str;
}

int main(int ac, char const *av[])
{
    if (ac != 2)
    {
        std::cout << "ERROR too many arguments !" << std::endl;
        return -1;
    }
    std::string strRpn = rpn(av[1]);
    std::cout << "END RPN: " << strRpn << std::endl;
    std::string rlt = skim(strRpn);
    return 0;
}
