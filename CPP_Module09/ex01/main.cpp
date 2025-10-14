#include "RPN.hpp"
#include <iostream>
#include <exception>
#include <string>


int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: bad arguments." << std::endl;
        return 1;
    }
    RPN pm;
    try
    {
        pm.handleArgs(av[1]);
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}