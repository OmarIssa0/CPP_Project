#include "BitcoinExchange.hpp"
#include <string>
#include <exception>
#include <iostream>
#include <algorithm>


BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : dataBase(other.dataBase)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        dataBase = other.dataBase;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::trim(std::string& str)
{
    while (!str.empty() && (str[0] == ' '  || str[0] == '\t'))
    {
        str.erase(str.begin());
    }
    while (!str.empty() && (str[str.size() - 1] == ' ' || str[str.size() - 1] == '\t'))
    {
        str.erase(str.end() - 1);
    }
}

void BitcoinExchange::handleFile(std::ifstream &file, const std::string &fileName, std::string &result)
{
    if (!file.is_open())
    {
        file.open(fileName.c_str());
    }
    if (!file.is_open())
        throw std::runtime_error("exception for open file");
    std::string key;
    std::string value;
    while (getline(file, result))
    {
              size_t foundSub = result.find("|");
        if (foundSub == std::string::npos)
        {
            std::cout << "Error :" + result << std::endl;
            continue;
        }
        key = result.substr(0, foundSub);
        trim(key);
        if (key.empty())
        {
            std::cout << "Error empty:" + key << std::endl;
            continue;
        }
        value = result.substr(foundSub + 1, result.size());
        trim(value);
        if (value.empty())
        {
            std::cout << "Error empty:" + value << std::endl;
            continue;
        }
        char *endptr = NULL; 
        double num = strtod(value.c_str(), &endptr);
        if (num < 0 || num > 1000)
        {
            std::cout << "Error num 0/1000 :" + value << std::endl;
            continue;    
        }
        std::cout << "key:" + key + "   " + "value: " + value << std::endl;
    }
}