#include "Span.hpp"
#include <climits>
#include <vector>

int main ()
{
    try
    {
        int size = 1000000;
        std::cout << "-------------- (Large Test - 1M elements) --------------" << std::endl;
        Span sp(size);
        std::vector<int> numbers;
        for (int i = 0; i < size; i++)
            numbers.push_back(i);
        
        sp.addNumbers(numbers.begin(), numbers.end());
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    try
    {
        int size = 10;
        std::cout << "-------------- (Small Test - 10 elements) --------------" << std::endl;
        Span sp(size);
        for (size_t i = 0; i < static_cast<size_t>(size); i++)
        {
            sp.addNumber(i); 
            std::cout << "Added: " << i << std::endl;
        }
        std::cout << "-------------- (Results) --------------" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // Test subject requirement
    std::cout << "-------------- (Subject Test) --------------" << std::endl;
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    // Test exception handling
    std::cout << "-------------- (Exception Tests) --------------" << std::endl;
    try
    {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        // This should throw an exception
        sp.addNumber(4);
    }
    catch (const std::exception &e)
    {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }
    
    try
    {
        Span sp(1);
        sp.addNumber(42);
        // This should throw an exception (only one number)
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }
    
    try
    {
        Span sp(0);
        // This should throw an exception (no numbers)
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }
    
    return 0;
}