#ifndef SPAN_HPP
#define SPAN_HPP

#include <list>
#include <stdexcept>

class Span
{
    //---------- variable(s)---------- 
    private:
        std::list<int>  listInts;
        unsigned int    n;

    //---------- constructor(s) and destructor ---------- 
    private:
        Span(void);

    public:
        Span(const Span &span);
        Span(unsigned int N);
        ~Span(void);

    //---------- function(s) ---------- 
    private:
        void isValidSpanRange(void) const throw (std::runtime_error);

    public:
        //operator(s) overload
        Span &operator=(const Span &rhs);

        //getter(s)
        unsigned int getN(void) const;
        const std::list<int> &getList(void) const;

        //others
        void addNumber(int number) throw (std::runtime_error);
        void addNumber(std::list<int>::const_iterator begin, std::list<int>::const_iterator end) throw (std::runtime_error);
        unsigned int    longestSpan(void) const;
        unsigned int    shortestSpan(void) const;

};

#endif
