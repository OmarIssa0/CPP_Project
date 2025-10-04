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

    public:
        Span(int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        void addNumber(int);
        int shortestSpan();
        int longestSpan();
};

#endif 
