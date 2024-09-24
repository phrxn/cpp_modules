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
        Fixed &operator=(const Fixed &fixed);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
