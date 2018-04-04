#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *strPtr = &str;
    std::string &strRef = str;

    std::cout << "With pointer: " << *strPtr << std::endl;
    std::cout << "With reference: " << strRef << std::endl;

    return 0;
}
