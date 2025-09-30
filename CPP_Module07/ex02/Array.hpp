#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T>
class Array 
{
    private:    
        T *data;
        unsigned int len;
    public:
        Array() : data(nullptr), len(0) {};

        Array(unsigned int n) : data(new T[n]()), len(n) {};

        Array(const Array &other) : 

        Array
}


#endif
