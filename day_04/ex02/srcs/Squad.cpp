#include <iostream>
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"

Squad::Squad(void) : _nbUnits(0), _spaceMarines(NULL)
{
}

Squad::Squad(Squad const &src)
{
    *this = src;
}

Squad::~Squad()
{
    for (int i = 0; i < this->_nbUnits; i++)
        delete this->_spaceMarines[i];
    delete[] this->_spaceMarines;
}

int Squad::push(ISpaceMarine *marine)
{
    if (marine == NULL)
        return this->_nbUnits;

    for (int i = 0; i < this->_nbUnits; i++)
    {
        if (this->_spaceMarines[i] == marine)
            return this->_nbUnits;
    }

    ISpaceMarine **tmp = new ISpaceMarine *[this->_nbUnits + 1];

    std::memcpy(&tmp, &this->_spaceMarines, sizeof(ISpaceMarine *) * this->_nbUnits);

    tmp[this->_nbUnits] = marine;

    this->_nbUnits++;

    this->_spaceMarines = tmp;
    return this->_nbUnits;
}

int Squad::getCount() const
{
    return this->_nbUnits;
}

ISpaceMarine *Squad::getUnit(int n) const
{
    if (n > this->_nbUnits)
        return NULL;
    return this->_spaceMarines[n];
}

// ISpaceMarine **Squad::getSpaceMarines() const
// {
//     return this->_spaceMarines;
// }

Squad &Squad::operator=(Squad const &rhs)
{
    this->_nbUnits = rhs.getCount();

    ISpaceMarine **tmp = new ISpaceMarine *[this->_nbUnits];
    for (int i = 0; i < this->_nbUnits; i++)
        tmp[i] = rhs.getUnit(i)->clone();

    this->_spaceMarines = tmp;
    return *this;
}
