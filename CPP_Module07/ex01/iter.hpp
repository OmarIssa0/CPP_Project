#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstdlib>

template <typename T, typename F> void iter(T *array, const size_t length, F fun)
{
    for (size_t i = 0; i < length; i++)
        fun(array[i]);    
}

#endif