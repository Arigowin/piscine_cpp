#include <iostream>
#include "ScalarConversion.hpp"

ScalarConversion::ScalarConversion(void) {}

std::string const ScalarConversion::getValue(void) const
{
    return this->_value;
}

ScalarConversion &ScalarConversion::operator=(ScalarConversion const &rhs)
{
    (void)rhs;
    return *this;
}

ScalarConversion::ScalarConversion(ScalarConversion const &src)
{
    *this = src;
}

ScalarConversion::ScalarConversion(std::string const value) : _value(value) {}

ScalarConversion::~ScalarConversion() {}

ScalarConversion::operator char()
{
    if (this->_value.length() == 1 && std::isgraph(this->_value[0]) && !std::isdigit(this->_value[0]))
        return this->_value[0];

    int tmp = std::atoi(this->_value.c_str());
    if ((errno && tmp == 0) || (tmp < 33 || tmp >= 127))
    {
        if (!errno && !std::isgraph(tmp) && tmp >= 0 && tmp <= 127)
            throw std::invalid_argument("Non displayable");
        throw std::invalid_argument("impossible");
    }
    return static_cast<char>(tmp);
}

ScalarConversion::operator int()
{
    if (this->_value.length() ==1 && !std::isdigit(this->_value[0]))
        return this->_value[0];

    double tmp = std::atof(this->_value.c_str());

    if ((errno && tmp == 0) || (std::numeric_limits<int>::max() < tmp || std::numeric_limits<int>::min() > tmp))
        throw std::invalid_argument("impossible");
    return static_cast<int>(tmp);
}

ScalarConversion::operator float()
{
    if (this->_value.length() == 1 && !std::isdigit(this->_value[0]))
        return this->_value[0];

    double tmp = std::atof(this->_value.c_str());
    if (errno && tmp == 0)
        throw std::invalid_argument("impossible");
    return static_cast<float>(tmp);
}

ScalarConversion::operator double()
{
    if (this->_value.length() == 1 && !std::isdigit(this->_value[0]))
        return this->_value[0];

    double tmp = std::atof(this->_value.c_str());

    if (errno && tmp == 0)
        throw std::invalid_argument("impossible");
    return static_cast<double>(tmp);
}
