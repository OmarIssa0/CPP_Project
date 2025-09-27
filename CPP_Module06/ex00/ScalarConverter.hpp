#include <string>
#include <iostream>

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

public:
    static void convert(const std::string &value);
};

#endif