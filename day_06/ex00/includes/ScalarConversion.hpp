#ifndef SCALARACONVERSION_HPP
#define SCALARACONVERSION_HPP

#include <iostream>

class ScalarConversion
{
  private:
    ScalarConversion(void);
    ScalarConversion(ScalarConversion const &src);

    std::string const getValue(void) const;
    ScalarConversion &operator=(ScalarConversion const &rhs);

    std::string const _value;

  public:
    ScalarConversion(std::string value);
    ~ScalarConversion(void);

    operator char();
    operator float();
    operator int();
    operator double();
};

#endif //SCALARACONVERSION_HPP
