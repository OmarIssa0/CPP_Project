#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat T("One", 42);
        std::cout << T << std::endl;
        for (int i = 0; i < 160; i++)
            T.decrementGrade();
        std::cout << "Test: " << std::endl;
        std::cout << T << std::endl;
    }
    catch(std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    std::cout << "Program not stoped:" << std::endl;
    try
    {
        Bureaucrat T("Test2", -1);
        std::cout << T << std::endl;
    }
    catch(std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
    
    std::cout << "Program not stoped:" << std::endl;
    try
    {
        Bureaucrat T("Test three", 42);
        std::cout << T << std::endl;
        for (int i = 0; i > -5; i--)
            T.incrementGrade();
        std::cout << "Test: " << std::endl;
        std::cout << T << std::endl;
    }
    catch(std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
    return 0;
}