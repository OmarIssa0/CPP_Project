#include <string>
#include <iostream>
#include "ScalarConverter.hpp"

int main (int ac, char **av)
{
    (void)av;
    if (ac != 2)
        return (std::cout << "./convert [value]", 1);
    ScalarConverter::convert(av[1]);
    return 0;
}