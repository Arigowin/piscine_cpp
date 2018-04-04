#include <iostream>
#include <fstream>

std::string findAndReplace(size_t index, std::string str, std::string s1, std::string s2)
{
    while (index != std::string::npos)
    {
        index = str.find(s1, index);

        if (index == std::string::npos)
            continue;

        str = str.replace(index, s2.length(), s2);
    }
    return str;
}

int filestream(std::string filename, std::string s1, std::string s2)
{
    std::ifstream ifs(filename);
    std::ofstream ofs(filename + ".replace");
    if (!ifs || !ofs)
    {
        std::cout << "While opening a file an error is encountered" << std::endl;
        return -1;
    }

    std::string tmp;
    while (!ifs.eof())
    {
        size_t index = 0;

        ifs >> tmp;
        if (ifs.eof())
            break;

        tmp = findAndReplace(index, tmp, s1, s2);

        ofs << tmp << std::endl;
    }
    ofs.close();
    ifs.close();

    return 0;
}

int main(int ac, char const *av[])
{
    if (ac != 4)
        return -1;

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    return filestream(filename, s1, s2);
}
