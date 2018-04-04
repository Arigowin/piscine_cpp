#include <iostream>

void add(int &s)
{
    s += 5;
}

void init(int &s)
{
    s = 0;
}

void diplay(int &s)
{
    std::cout << s << std::endl;
}

void add(float &s)
{
    s += 3.0f;
}

void init(float &s)
{
    s = 0.0f;
}

void diplay(float &s)
{
    std::cout << std::fixed << s << "f" << std::endl;
}

void add(std::string &s)
{
    s += " !";
}

void init(std::string &s)
{
    s = "hello World";
}

void diplay(std::string &s)
{
    std::cout << std::fixed << s << std::endl;
}

template <typename T>
void iter(T *array, size_t const length, void (*fct)(T &))
{
    for (size_t i = 0; i < length; ++i)
        fct(array[i]);
}

int main(void)
{
    int a[5];

    iter<int>(a, 5, init);
    iter<int>(a, 5, add);
    iter<int>(a, 5, diplay);

    float b[5];

    iter<float>(b, 5, init);
    iter<float>(b, 5, add);
    iter<float>(b, 5, diplay);

    std::string c[5];

    iter<std::string>(c, 5, init);
    iter<std::string>(c, 5, add);
    iter<std::string>(c, 5, diplay);


    return 0;
}
