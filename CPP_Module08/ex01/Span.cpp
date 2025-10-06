#include "Span.hpp"
#include <climits>
#include <algorithm>

Span::Span(unsigned int N) : maxSize(N)
{
    myNumber.reserve(N);
};

Span::Span(const Span &other)
{
    *this = other;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        myNumber = other.myNumber;
        maxSize = other.maxSize;
    }
    return *this;
}

Span::~Span()
{

}

void Span::addNumber(int num)
{
    if (myNumber.size() >= maxSize)
        throw std::runtime_error("Span is full, cannot add more numbers");
    myNumber.push_back(num);
}

// void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
// {
//    for (; begin != end; ++begin)
//    {
//         addNumber(*begin);
//     }
// }

/* 
   ! myNumber = [5, 3, 17, 9]
   ! sorted = [3, 5, 9, 17]
   ! diffs = 5-3=2, 9-5=4, 17-9=8
   ! shortestSpan = 2
*/
int Span::shortestSpan()
{
    if (myNumber.size() < 2)
        throw std::runtime_error("Not enough numbers to find span");
    std::vector<int> sorted = myNumber;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = INT_MAX;
    for (size_t i = 0; i < sorted.size() - 1; i++)
        minSpan = std::min(minSpan, sorted[i + 1] - sorted[i]);
    return minSpan;
}

/*
    * myNumber = [5, 3, 17, 9]
    * minVal = 3
    * maxVal = 17
    * longestSpan = 17-3 = 14
*/
int Span::longestSpan()
{
    if (myNumber.size() < 2)
        throw std::runtime_error("Not enough numbers to find span");
    std::vector<int> sorted = myNumber;
    std::sort(sorted.begin(), sorted.end());
    return (sorted[sorted.size() - 1] - sorted[0]);
}
