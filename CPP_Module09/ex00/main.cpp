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
        std::ifstream file;
        std::string result;
        btc.handleFile(file, av[1], result);
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}