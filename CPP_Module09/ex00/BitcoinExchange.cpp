#include "BitcoinExchange.hpp"
#include <string>
#include <exception>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange()
{
    loadDatabase();
}

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
    while (!str.empty() && (str[0] == ' ' || str[0] == '\t' || str[0] == '\n' || str[0] == '\r'))
    {
        str.erase(str.begin());
    }
    while (!str.empty() && (str[str.size() - 1] == ' ' || str[str.size() - 1] == '\t' || str[str.size() - 1] == '\n' || str[str.size() - 1] == '\r'))
    {
        str.erase(str.end() - 1);
    }
}

void BitcoinExchange::loadDatabase()
{
    std::ifstream dataBaseFile("data.csv");
    if (!dataBaseFile.is_open())
        throw std::runtime_error("Error: could not open database file.");
    
    std::string line;
    std::getline(dataBaseFile, line); // skip header
    
    while (std::getline(dataBaseFile, line))
    {
        size_t pos = line.find(",");
        if (pos == std::string::npos)
            continue;
            
        std::string date = line.substr(0, pos);
        std::string value = line.substr(pos + 1);
        trim(date);
        trim(value);
        
        char *endptr = NULL;
        double rate = strtod(value.c_str(), &endptr);
        if (*endptr == '\0')
            dataBase[date] = rate;
    }
    dataBaseFile.close();
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
        
    for (size_t i = 0; i < date.size(); ++i)
    {
        if (i == 4 || i == 7) continue;
        if (date[i] < '0' || date[i] > '9')
            return false;
    }
    
    int year = std::atoi(date.substr(0,4).c_str());
    int month = std::atoi(date.substr(5,2).c_str());
    int day = std::atoi(date.substr(8,2).c_str());
    
    if (month < 1 || month > 12)
        return false;
        
    int daysInMonth;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
            daysInMonth = 31; break;
        case 4: case 6: case 9: case 11: 
            daysInMonth = 30; break;
        case 2:
            daysInMonth = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
            break;
        default: 
            return false;
    }
    
    return (day >= 1 && day <= daysInMonth);
}

double BitcoinExchange::getExchangeRate(const std::string &date)
{
    std::map<std::string, double>::iterator it = dataBase.find(date);
    if (it != dataBase.end())
        return it->second;
    
    it = dataBase.lower_bound(date);
    if (it == dataBase.begin())
        throw std::runtime_error("Error: no data available for date " + date);
    
    --it;
    return it->second;
}

void BitcoinExchange::handleFile(const std::string &fileName, std::string &)
{
    std::ifstream file(fileName.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");
    
    std::string line;
    std::getline(file, line);
    if (line != "date | value")
        throw std::runtime_error("Error: bad input.");
    
    while (std::getline(file, line))
    {
        size_t pipePos = line.find(" | ");
        if (pipePos == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string date = line.substr(0, pipePos);
        std::string valueStr = line.substr(pipePos + 3);
        
        trim(date);
        trim(valueStr);
        
        // Validate date
        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        // Validate value
        if (valueStr.empty())
        {
            std::cout << "Error: bad input => " << valueStr << std::endl;
            continue;
        }
        
        char *endptr = NULL;
        double value = strtod(valueStr.c_str(), &endptr);
        
        if (*endptr != '\0')
        {
            std::cout << "Error: bad input => " << valueStr << std::endl;
            continue;
        }
        
        if (value < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        
        if (value > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        
        try
        {
            double rate = getExchangeRate(date);
            double result = value * rate;
            std::cout << date << " => " << value << " = " << result << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    
    file.close();
}
