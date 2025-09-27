#include <iostream>
#include <string>
#include <cstdlib> // std::strtod
#include <limits>  // std::numeric_limits
#include <iomanip> // std::fixed, std::setprecision
#include <cmath>
#include <cerrno>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {};

ScalarConverter::~ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
};

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
};

// ! --> nan & nanf -> not a number
// ! inf- & inf+ -> Infinity+/-
static bool handleSpecialLiterals(const std::string &value)
{
    if (value == "nan" || value == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return true;
    }
    if (value == "+inf" || value == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
        return true;
    }
    if (value == "-inf" || value == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return true;
    }
    return false;
}

// ! 'A' --> true(65 ASCII) / '5' --> false
static bool convertToChar(const std::string &value)
{
    if (value.length() == 1 && !isdigit(value[0]))
    {
        char c = value[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return true;
    }
    return false;
}

// ! ERANGE --> (overflow/underflow)
static bool parseToDouble(const std::string &value, double &outValue)
{
    if (value.empty())
        return false;
    std::string str = value;
    // ! 42.0f -> 42.0
    if (str.size() > 1 && str[str.size() - 1] == 'f')
        str.resize(str.size() - 1);
    char *endptr = NULL;
    errno = 0;
    double val = std::strtod(str.c_str(), &endptr);
    if (*endptr != '\0' || errno == ERANGE)
        return false;
    outValue = val;
    return true;
}

static void printChar(double value)
{
    if (std::isnan(value) || std::isinf(value) ||
        value < std::numeric_limits<char>::min() ||
        value > std::numeric_limits<char>::max())
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }

    char c = static_cast<char>(value);
    if (!std::isprint(static_cast<unsigned char>(c)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
}



void ScalarConverter::convert(const std::string &value)
{
    if (convertToChar(value))
        return;
    if (handleSpecialLiterals(value))
        return;
    double num;
    if (!parseToDouble(value, num))
    {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
        return;
    }
    printChar(num);
    // print int
    if (std::isnan(num) || std::isinf(num) || num < static_cast<double>(std::numeric_limits<int>::min()) || num > static_cast<double>(std::numeric_limits<int>::max()))
    {
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        std::cout << "int: " << static_cast<int>(num) << std::endl;
    }

    // determine precision from input string (preserve decimals if provided)
    int precision = 0;
    std::size_t dotPos = value.find('.');
    if (dotPos != std::string::npos)
    {
        // count digits after '.' until 'f' or end
        std::size_t end = value.find('f', dotPos);
        if (end == std::string::npos)
            end = value.size();
        precision = static_cast<int>(end - dotPos - 1);
        if (precision < 0)
            precision = 0;
    }

    // print float
    if (std::isnan(num))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(num))
        std::cout << "float: " << (num < 0 ? "-inff" : "inff") << std::endl;
    else
    {
        // if no decimal part in input, show one decimal
        if (precision == 0)
            precision = 1;
        std::cout << "float: " << std::fixed << std::setprecision(precision) << static_cast<float>(num) << "f" << std::endl;
        // reset formatting
        std::cout.unsetf(std::ios::fixed);
    }

    // print double
    if (std::isnan(num))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(num))
        std::cout << "double: " << (num < 0 ? "-inf" : "inf") << std::endl;
    else
    {
        if (precision == 0)
            precision = 1;
        std::cout << "double: " << std::fixed << std::setprecision(precision) << static_cast<double>(num) << std::endl;
        std::cout.unsetf(std::ios::fixed);
    }
}