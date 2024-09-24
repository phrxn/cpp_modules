#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>
#include <ostream>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
    // -------------------- types --------------------
    public:
        typedef typename std::stack<T>::container_type::iterator                iterator;
        typedef typename std::stack<T>::container_type::const_iterator          const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator        reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator  const_reverse_iterator;

    // -------------------- constructor(s) and destructor --------------------
    public:
        MutantStack<T>(void);
        MutantStack<T>(const MutantStack<T> &mutantStack);
        ~MutantStack<T>(void);

    // -------------------- functions -------------------
    public:
	
		// operator(s) overload
		MutantStack<T> &	operator=(MutantStack<T> const & mutantStack);
		
		// others
		MutantStack<T>::iterator	begin(void);
		MutantStack<T>::iterator	end(void) ;
		MutantStack<T>::const_iterator	begin(void) const ;
		MutantStack<T>::const_iterator	end(void) const ;
		MutantStack<T>::reverse_iterator	rbegin(void) ;
		MutantStack<T>::reverse_iterator	rend(void) ;
		MutantStack<T>::const_reverse_iterator	rbegin(void) const ;
		MutantStack<T>::const_reverse_iterator	rend(void) const ;
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &mutantStack) : std::stack<T>(mutantStack)
{
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
}

template <typename T>
MutantStack<T>  &MutantStack<T>::operator=(MutantStack<T> const &mutantStack)
{
    if (this == &mutantStack)
        return *this;
    this->c = mutantStack.c;
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	 return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin(void) const 
{
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end(void) const 
{
    return this->c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin(void) 
{
    return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend(void) 
{
    return this->c.rend();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rbegin(void) const 
{
    return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rend(void) const 
{
    return this->c.rend();
}

#endif
