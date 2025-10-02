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
        Array() : data(0), len(0) {};

        Array(unsigned int n) : data(new T[n]()), len(n) {};

        Array(const Array &other) : data(0), len(0) 
        {
            *this = other;
        };

        ~Array() 
        {
            delete[] data;
        };

        Array &operator=(const Array &other) 
        {
            if (this != &other) 
            {
                delete[] data;
                len = other.len;
                data = new T[len]();
                for (unsigned int i = 0; i < len; ++i) 
                {
                    data[i] = other.data[i];
                }
            }
            return *this;
        }

        const T &operator[](unsigned int index) const 
        {
            if (index >= len) 
            {
                throw std::out_of_range("Index out of bounds");
            }
            return data[index];
        }
        T &operator[](unsigned int index) 
        {
            if (index >= len) 
            {
                throw std::out_of_range("Index out of bounds");
            }
            return data[index];
        }
        unsigned int size() const 
        {
            return len;
        }
};


#endif
