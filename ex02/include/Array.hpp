#ifndef ARRAY_HPP
#define ARRAY_HPP
# include <iostream>

template <typename T>
class Array
{
    private:
        T *_array;
        unsigned int _size;
    public:
        Array(void);
        Array(unsigned int n);
        Array(Array const &src);
		Array	&operator=(Array const &rhs);
		~Array(void);
        T				*getAddress() const;
        unsigned int	getSize() const;
        unsigned int size(void) const;
        class IndexOutOfRangeException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#include "Array.tpp"

#endif