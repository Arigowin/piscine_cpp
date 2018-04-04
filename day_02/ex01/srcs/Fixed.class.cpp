#include <iostream>
#include <cmath>
#include "Fixed.class.hpp"

Fixed::Fixed() : _fixPoint(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(int const n)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixPoint = (n << this->_fracBits);
}

Fixed::Fixed(float const n)
{
    std::cout << "Float constructor called " << std::endl;
    this->_fixPoint = ((int)((n) * (1 << this->_fracBits)));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return this->_fixPoint;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixPoint = raw;
}

float Fixed::toFloat(void) const
{
    return (((float)(this->_fixPoint)) / (1 << this->_fracBits));
}

int Fixed::toInt(void) const
{
    return (this->_fixPoint >> this->_fracBits);
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    this->_fixPoint = rhs.getRawBits();
    return *this;
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
    o << rhs.toFloat();
    return o;
}
