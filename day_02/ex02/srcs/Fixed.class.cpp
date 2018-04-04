#include <iostream>
#include <cmath>
#include "Fixed.class.hpp"

Fixed::Fixed() : _fixPoint(0)
{
}

Fixed::Fixed(Fixed const &src)
{
    *this = src;
}

Fixed::Fixed(int const n)
{
    this->_fixPoint = (n << this->_fracBits);
}

Fixed::Fixed(float const n)
{
    this->_fixPoint = (int)(n * (1 << this->_fracBits));
}

Fixed::~Fixed()
{
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
    this->_fixPoint = rhs.getRawBits();
    return *this;
}

Fixed &Fixed::operator+(Fixed const &rhs)
{
    this->_fixPoint += rhs.getRawBits();
    return *this;
}

Fixed &Fixed::operator-(Fixed const &rhs)
{
    this->_fixPoint -= rhs.getRawBits();
    return *this;
}

Fixed &Fixed::operator*(Fixed const &rhs)
{
    this->_fixPoint = (float)((this->_fixPoint * rhs.getRawBits()) >> this->_fracBits);
    return *this;
}

Fixed &Fixed::operator/(Fixed const &rhs)
{
    this->_fixPoint = ((this->_fixPoint << this->_fracBits) / rhs.getRawBits());
    return *this;
}

bool Fixed::operator>(Fixed const &rhs) const
{
    return this->_fixPoint > rhs.getRawBits();
}

bool Fixed::operator<(Fixed const &rhs) const
{
    return this->_fixPoint < rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const &rhs) const
{
    return this->_fixPoint >= rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const &rhs) const
{
    return this->_fixPoint <= rhs.getRawBits();
}

bool Fixed::operator==(Fixed const &rhs) const
{
    return this->_fixPoint == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const &rhs) const
{
    return this->_fixPoint != rhs.getRawBits();
}

Fixed &Fixed::operator++()
{
    this->_fixPoint += 1;
    return *this;
}

Fixed &Fixed::operator--()
{
    this->_fixPoint -= 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);

    ++(*this);

    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);

    --(*this);

    return tmp;
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
    o << rhs.toFloat();
    return o;
}

Fixed const &Fixed::min(Fixed const &lhs, Fixed const &rhs)
{
    return (lhs.getRawBits() > rhs.getRawBits() ? lhs : rhs);
}

Fixed const &Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
    return (lhs.getRawBits() > rhs.getRawBits() ? lhs : rhs);
}
