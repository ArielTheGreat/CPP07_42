#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *p, int length, F func)
{
    for(int i = 0; i < length; i++)
    {
        func(p[i]);
    }
}

template <typename T>
void my_print(T &element)
{
    std::cout << element << " ";
}

#endif