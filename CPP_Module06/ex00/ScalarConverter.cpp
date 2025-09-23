#include <iostream>
#include <string>
#include <cstdlib>   // std::strtod
#include <limits>    // std::numeric_limits
#include <iomanip>   // std::fixed, std::setprecision
#include <cmath> 
#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string value)
{
    if (value.length() == 1 && !std::isdigit(value[0]))
    {
        char c = value[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl; 
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }
    char *end;
    double d = std::strtod(value.c_str(), &end);
    if (*end != '\0')
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << value + "f" << std::endl;
        std::cout << "double: " << value << std::endl;
        return;
    }
    (void)d;
    return;
}