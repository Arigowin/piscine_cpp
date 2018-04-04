#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
  private:
    T *_array;
    unsigned int _size;

  public:
    Array<T>(void);
    Array<T>(unsigned int n);
    Array<T>(Array<T> const &src);
    ~Array<T>(void);

    unsigned int size(void) const;
    T *getArray(void) const;

    Array<T> &operator=(Array<T> const &rhs);
    T &operator[](unsigned int idx) const;
};

#endif //ARRAY_HPP

template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(Array const &src)
{
    *this = src;
}

template <typename T>
Array<T>::~Array()
{
    delete [] this->_array;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    this->_array = new T[n]();
}

template <typename T>
unsigned int Array<T>::size(void) const
{
    return this->_size;
}

template <typename T>
T *Array<T>::getArray(void) const
{
    return this->_array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &rhs)
{
    this->_size = rhs.size();
    this->_array = new T[this->_size]();
    for (unsigned int i = 0; i < this->_size; ++i) {
        this->_array[i] = rhs.getArray()[i];
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int idx) const
{
    if (idx >= this->_size)
        throw std::exception();
    return this->_array[idx];
}
