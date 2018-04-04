#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP

class Fixed
{
  public:
    Fixed();
    Fixed(Fixed const &src);
    ~Fixed(void);

    Fixed &operator=(Fixed const &rhs);

    int getRawBits(void) const;
    void setRawBits(int const raw);

  private:
    int _fixPoint;
    static const int _nbFrac = 8;
};

#endif //FIXED_CLASS_HPP
