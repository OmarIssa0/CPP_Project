#include "Span.hpp"

int main ()
{
    try
    {
        int size = -10000;
        std::cout << "-------------- (start Sp -) --------------" << std::endl;
        Span sp(size);
        for (size_t i = 0; i < static_cast<size_t>(size); i++)
            sp.addNumber(i); 
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        int size = 1000000;
        std::cout << "-------------- (Start Sp +) --------------" << std::endl;
        Span sp(size);
        for (size_t i = 0; i < static_cast<size_t>(size); i++)
            sp.addNumber(i); 
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    try
    {
        int size = 10;
        std::cout << "-------------- (Start Sp) --------------" << std::endl;
        Span sp(size);
        for (size_t i = 0; i < static_cast<size_t>(size); i++)
        {
            sp.addNumber(i); 
            std::cout << i + 1 << std::endl;
        }
        std::cout << "-------------- (Start Sp shortestSpan and longestSpan) --------------" << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}