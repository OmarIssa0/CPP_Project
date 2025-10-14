#include "RPN.hpp"


RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
    numbers = other.numbers;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        numbers = other.numbers;
    }
    return *this;
}

RPN::~RPN()
{
}

void RPN::handleArgs(const std::string &args)
{
    if (args.empty())
        throw std::runtime_error("Error: bad input.");
    for (size_t i = 0; i < args.size(); ++i)
    {
        if (args[i] != ' ' && args[i] != '+' && args[i] != '-' && 
            args[i] != '*' && args[i] != '/' && !isdigit(args[i]))
            throw std::runtime_error("Error: bad input.");
        if (isdigit(args[i]) && i + 1 < args.size() && args[i + 1] != ' ')
            throw std::runtime_error("Error: bad input.");
    }
    for (size_t i = 0; i < args.size(); ++i)
    {
        if (isdigit(args[i]))
        {
            numbers.push(args[i] - '0');
        }
        else if (args[i] == '+' || args[i] == '-' || args[i] == '*' || args[i] == '/')
        {
            if (numbers.size() < 2)
                throw std::runtime_error("Error: not enough numbers in the stack.");
            int b = numbers.top();
            numbers.pop();
            int a = numbers.top();
            numbers.pop();
            int result;
            switch (args[i])
            {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    if (b == 0)
                        throw std::runtime_error("Error: division by zero.");
                    result = a / b;
                    break;
                default:
                    throw std::runtime_error("Error: unknown operator.");
            }
            numbers.push(result);
        }
    }
    if (numbers.size() != 1)
        throw std::runtime_error("Error: too many numbers in the stack.");
    std::cout << numbers.top() << std::endl;
    numbers.pop();
    if (!numbers.empty())
        throw std::runtime_error("Error: stack is not empty after evaluation.");
}
