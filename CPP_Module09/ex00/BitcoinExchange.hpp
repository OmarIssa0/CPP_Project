#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>

class BitcoinExchange
{ 
    private:
        std::map<std::string, float> dataBase;
    
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        /*
            ! controller:
                * 1) validation (empty, 0/1000 or -1)
                * 2) check the file
        */
        void    handleFile(std::ifstream &file, const std::string &fileName, std::string &result);
        void trim(std::string& str);
};


#endif