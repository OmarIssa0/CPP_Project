#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <iostream>

class PmergeMe
{
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        
        template <typename T>
        bool isSorted(const T& container) const;
        void sortVector(std::vector<int>& vec);
        void sortDeque(std::deque<int>& deq);
        
};

#endif