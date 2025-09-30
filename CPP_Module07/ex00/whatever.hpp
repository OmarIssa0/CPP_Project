#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T> void swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

template <typename T> T min(T val1, T val2)
{
    return val1 < val2 ? val1 : val2;
}

template <typename T> T max(T val1, T val2)
{
    return val1 > val2 ? val1 : val2;
}

#endif