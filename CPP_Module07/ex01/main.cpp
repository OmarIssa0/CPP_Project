#include <iostream>
#include "iter.hpp"

void printString(std::string const &s)
{
    std::cout << s << std::endl;
}

void printInt(int num)
{
    std::cout << num << std::endl;
}

int main()
{
    std::string arr[3] = {"Hello", "42", "School"};
    iter(arr, 3, printString);
    
    int arrNum[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ::iter(arrNum, static_cast<size_t>(sizeof(arrNum) / 4), printInt);

    return 0;
}
