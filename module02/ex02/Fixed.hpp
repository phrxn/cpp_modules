#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    //variables
    private:
        static const int fractional = 8;
        int raw;

    public:
        //constructor(s) and destructor(s)
        Fixed();
        Fixed(const Fixed &fixed);
        Fixed(const int i);
        Fixed(const float f);
        ~Fixed();

        //functions
        int   getRawBits(void) const;
        void  setRawBits(int const raw);
        float toFloat(void) const;
        int   toInt(void) const;

        //operator(s) overload
        Fixed &operator=(const Fixed &rhs);
        bool  operator>(const Fixed &rhs) const;
        bool  operator<(const Fixed &rhs) const;
        bool  operator>=(const Fixed &rhs) const;
        bool  operator<=(const Fixed &rhs) const;
        bool  operator==(const Fixed &rhs) const;
        bool  operator!=(const Fixed &rhs) const;

        Fixed operator+(Fixed const &rhs) const;
        Fixed operator-(Fixed const &rhs) const;
        Fixed operator*(Fixed const &rhs) const;
        Fixed operator/(Fixed const &rhs) const;

        Fixed &operator++(void);
        Fixed operator++(int);
        Fixed &operator--(void);
        Fixed operator--(int);

        static Fixed &min(Fixed &lhs, Fixed &rhs);
        static Fixed const &min(const Fixed &lhs, const Fixed &rhs);
        static Fixed &max(Fixed &lhs, Fixed &rhs);
        static Fixed const &max(const Fixed &lhs, const Fixed &rhs);
};

std::ostream &operator<<(std::ostream &os, const Fixed &rhs);

#endif
