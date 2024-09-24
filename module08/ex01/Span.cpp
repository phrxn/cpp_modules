#include "Span.hpp"

#include <iterator>
#include <algorithm>
#include <limits>

#include <iostream>
Span::Span() : n(0)
{
}

Span::Span(const Span &span)
{
    *this = span;
}

Span::Span(unsigned int N) : n(N)
{
}

Span::~Span(void)
{
}

void Span::isValidSpanRange(void) const throw (std::runtime_error)
{
    if (listInts.size() == 0)
        throw std::runtime_error("The list is empty.");
    if (listInts.size() == 1)
        throw std::runtime_error("The list has only 1 item .");
}

//operator(s) overload
Span &Span::operator=(const Span &rhs)
{
    if (this == &rhs) return *this;

    this->n = rhs.n;
    this->listInts = rhs.listInts;

    return (*this);
}

//getter(s)
unsigned int Span::getN(void) const
{
    return (this->n);
}

const std::list<int> &Span::getList(void) const
{
    return (this->listInts);
}

//others
void Span::addNumber(int number) throw (std::runtime_error)

{
    if (n == 0)
        throw std::runtime_error("Cannot add any number to this Span.");
    if (listInts.size() == n)
        throw std::runtime_error("This Span is full.");
    listInts.push_back(number);
}

void Span::addNumber(std::list<int>::const_iterator begin, std::list<int>::const_iterator end) throw (std::runtime_error)
{
    //return the number of elements
    std::size_t quantity = std::distance(begin, end);
    if (quantity == 0)
        return ;
    if (listInts.size() == n)
        throw std::runtime_error("This Span is full.");
    if ((this->n - this->listInts.size()) < quantity)
        throw std::runtime_error("It is not possible to add the list to Span as this would exceed the maximum limit.");
    this->listInts.insert(this->listInts.end(), begin, end);
}

unsigned int    Span::longestSpan(void) const
{
    isValidSpanRange();
    int highestValue = *std::max_element(this->listInts.begin(), this->listInts.end()); 
    int lowestValue = *std::min_element(this->listInts.begin(), this->listInts.end()); 
    return (static_cast<unsigned int>(highestValue) - static_cast<unsigned int>(lowestValue));
}

unsigned int    Span::shortestSpan(void) const
{
    isValidSpanRange();

    unsigned int lowestDistance = std::numeric_limits<unsigned int>::max();

    //temp ondered list
    std::list<int> listOrdenedInts(this->listInts);
    listOrdenedInts.sort();

    std::list<int>::const_iterator it = listOrdenedInts.begin();
    std::list<int>::const_iterator nextIt = ++it;
    it--;
    std::list<int>::const_iterator end = listOrdenedInts.end();

    while(nextIt != end)
    {
        unsigned int distance = static_cast<unsigned int> (*nextIt - *it);
        if (distance < lowestDistance)
            lowestDistance = distance;
        it++;
        nextIt++;
    }
    return (lowestDistance);
}

