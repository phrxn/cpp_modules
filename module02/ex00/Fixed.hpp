#ifndef FIXED_HPP
#define FIXED_HPP

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
        ~Fixed();

        //functions
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        //operator(s) overload
        Fixed &operator=(const Fixed &fixed);
};

#endif
