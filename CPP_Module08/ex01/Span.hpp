#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <exception>

class Span
{
    private:
        std::vector<int> myNumber;
        unsigned int maxSize;

    public:
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();
        void addNumber(int);
        template <typename T>
        void addNumbers(T begin, T end)
        {
            for (; begin != end; ++begin)
            {
                addNumber(*begin);
            }
        }
        int shortestSpan();
        int longestSpan();
};


#endif 
