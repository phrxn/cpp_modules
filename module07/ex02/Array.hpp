#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
template <typename T>
class Array
{
    // ---------- nested class(es) ----------
    public:
        class OutOfBoundsException : public std::exception
        {
            virtual const char * what() const throw()
            {
                return "The index value is invalid!";
            }
        };

    // ---------- variable(s) ----------
    private:
        T               *items;
        unsigned int    _size;

    // ---------- constructor(s) and destructor ----------
    public:
        Array(void) : items(new T[0]()), _size(0)
        {
        }
        Array(const Array &array) : items(0), _size(0)
        {
            *this = array;
        }
        Array(unsigned int n) : items(new T[n]), _size(n)
        {
        }
        ~Array(void)
        {
            delete[] items;
        }

    // ---------- functions ----------
    public:
        Array &operator=(const Array &rhs)
        {
            if (this == &rhs) return *this;

            T *new_items = new T[rhs._size];

            for (unsigned int count = 0; count < rhs._size; ++count)
                new_items[count] = rhs.items[count];

            delete[] this->items;

            this->items = new_items;
            this->_size = rhs._size;

            return *this;
        }

        T &operator[](unsigned int index) throw(Array::OutOfBoundsException)
        {
            if (index >= this->_size)
                throw (Array::OutOfBoundsException());
            return (this->items[index]);
        }

        unsigned int getSize(void) const
        {
            return (this->_size);
        }

};

#endif
