#include "Span.hpp"
#include <climits>
#include <algorithm>

Span::Span(int num) 
{
    myNumber.reserve(num);
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
    }
    return *this;
}

void Span::addNumber(int num)
{
    myNumber.push_back(num);
}

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

int Span::longestSpan()
{
    if (myNumber.size() < 2)
        throw std::runtime_error("Not enough numbers to find span");
    int minVal = *std::min_element(myNumber.begin(), myNumber.end());
    int maxVal = *std::max_element(myNumber.begin(), myNumber.end());

    return maxVal - minVal;
}
