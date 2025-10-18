#include "BitcoinExchange.hpp"
#include <iostream>
#include <exception>
#include <string>
#include <fstream>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    BitcoinExchange btc;
    try
    {
        btc.handleFile(av[1]);
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}