#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP

#include <iostream>

class Fixed
{
public:
  Fixed();
  Fixed(int const n);
  Fixed(float const n);
  Fixed(Fixed const &src);
  ~Fixed(void);

  Fixed &operator=(Fixed const &rhs);

  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;

private:
  int _fixPoint;
  static const int _fracBits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif //FIXED_CLASS_HPP
