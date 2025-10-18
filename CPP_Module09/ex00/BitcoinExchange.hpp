#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>

class BitcoinExchange
{ 
    private:
        std::map<std::string, double> dataBase;
        
        void    loadDatabase();
        bool    isValidDate(const std::string &date);
        double  getExchangeRate(const std::string &date);
        void    trim(std::string& str);
    
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        
        void    handleFile(const std::string &fileName);
};

#endif