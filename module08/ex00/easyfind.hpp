#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdexcept>

template <typename T>
typename T::const_iterator easyfind(const T &container, int item)
{
    typename T::const_iterator it;

    it = std::find(container.begin(), container.end(), item);
    if (it == container.end())
        throw (std::invalid_argument("The container doesn't have the item"));
    return (it);
}

template <typename T>
void printAContainer(const std::string &containerType, const T &container)
{
    std::cout << "container type: [" << containerType << "] values:{";
    std::copy(container.begin(), container.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << "}" << std::endl;
}
#endif
