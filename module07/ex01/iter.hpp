#ifndef ITER_HPP
#define ITER_HPP

#include <cstdlib>
#include <iostream>

template <typename T, typename F>
void    iter(T *array, size_t size, F f)
{
    for(size_t count = 0; count < size; count++)
        f(array[count]);
}

template <typename T>
void    increment(T &t)
{
    t++;
}

template <typename T>
void    decrement(T &t)
{
    t = t - 1;
}

template <typename T>
void printValue(const T &t)
{
    std::cout << t << std::endl;
}

template <typename T>
void printArray(const T *array, size_t size)
{
    for (size_t count = 0; count < size; count++)
    {
        std::cout << array[count];
        if (size - count > 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

#endif
