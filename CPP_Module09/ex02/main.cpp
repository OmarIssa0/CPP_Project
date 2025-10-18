#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <deque>
#include <vector>
#include <sys/time.h>
#include <iomanip>


int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: No input numbers provided." << std::endl;
        return 1;
    }
    std::vector<int> numbersVec;
    std::deque<int> numbersDeq;
    PmergeMe pmergeMe;
    for (int i = 1; i < argc; ++i)
    {
        char *my_arg = argv[i];
        for (size_t j = 0; my_arg[j]; j++)
        {
            if (!isdigit(my_arg[j]))
            {
                std::cerr << "Error: Invalid number '" << my_arg << "'." << std::endl;
                return 1;
            }
        }
        long num = std::strtol(my_arg, NULL, 10);
        if (num < 0 || num > 2147483647)
        {
            std::cerr << "Error: Number out of range '" << my_arg << "'." << std::endl;
            return 1;
        }
        numbersVec.push_back(static_cast<int>(num));
        numbersDeq.push_back(static_cast<int>(num));
    }
    bool isSorted = pmergeMe.isSorted(numbersVec);
    struct timeval start, end;
    long long time_vec, time_deq;
    std::cout << "Before: ";
    for (size_t i = 0; i < numbersVec.size(); ++i)
    {
        std::cout << numbersVec[i] << " ";
    }
    std::cout << std::endl;
    gettimeofday(&start, NULL);
    if (!isSorted)
    {
        pmergeMe.sortVector(numbersVec);
    }
    gettimeofday(&end, NULL);
    time_vec = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    
    gettimeofday(&start, NULL);
    if (!pmergeMe.isSorted(numbersDeq))
    {
        pmergeMe.sortDeque(numbersDeq);
    }
    gettimeofday(&end, NULL);
    time_deq = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    std::cout << "After: ";
    for (size_t i = 0; i < numbersVec.size(); ++i)
    {
        std::cout << numbersVec[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << numbersVec.size() << " elements with std::vector : " << static_cast<double>(time_vec) << " us" << std::endl;
    std::cout << "Time to process a range of " << numbersDeq.size() << " elements with std::deque  : " << static_cast<double>(time_deq) << " us" << std::endl;

    return 0;
}