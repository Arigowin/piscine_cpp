#include <iostream>
#include "PhoneBook.class.hpp"

int main(void)
{
    PhoneBook phoneBook;
    std::string cmd;
    bool ended = true;

    std::cout << "Welcome in the most awesome phone book of the WORLD !!!!" << std::endl;

    while (ended)
    {
        std::cout << "Please enter a command [ADD, SEARCH, EXIT]: ";
        std::cin >> cmd;

        if (cmd.compare("ADD") == 0)
        {
            phoneBook.add();
        }
        else if(cmd.compare("SEARCH") == 0)
        {
            phoneBook.search();
        }

        ended = cmd.compare("EXIT");

        if (std::cin.fail())
        {
            std::cout << "ERROR: Reading error. please try again!\n";
            std::cin.clear();
            std::cin.ignore();
        }
    }

    return 0;
}
