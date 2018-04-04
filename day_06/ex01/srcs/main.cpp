#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <ctime>

struct Data
{
    std::string s1;
    int n;
    std::string s2;
};

Data *deserialize(void *raw)
{
    return static_cast<Data *>(raw);
}

void *serialize(void)
{
    Data *raw = new Data;
    static char set[] = "abcdefghijklmnopqrstuvwxyz"
                        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                        "1234567890";

    for (int i = 0; i < 9; ++i)
        raw->s1 += set[static_cast<unsigned long>(std::rand()) % sizeof(set)];

    raw->n = rand();

    for (int i = 0; i < 9; ++i)
        raw->s2 += set[static_cast<unsigned long>(std::rand()) % sizeof(set)];

    return (raw);
}

int main(void)
{

    void *a = serialize();
    Data *b = deserialize(a);
    std::cout << b->s1 << std::endl;
    std::cout << b->n << std::endl;
    std::cout << b->s2 << std::endl;

    return 0;
}
