#include "PmergeMe.hpp"
#include <algorithm>
#include <iterator>

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    (void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    (void)other;
    return *this;
}

template <typename T>
bool PmergeMe::isSorted(const T& container) const
{
    typename T::const_iterator it = container.begin();
    if (it == container.end())
        return true;
    typename T::const_iterator next = it;
    ++next;
    for (; next != container.end(); ++it, ++next)
    {
        if (*next < *it)
            return false;
    }
    return true;
}

template bool PmergeMe::isSorted<std::vector<int> >(const std::vector<int>&) const;
template bool PmergeMe::isSorted<std::deque<int> >(const std::deque<int>&) const;

void PmergeMe::sortVector(std::vector<int>& vec)
{
    if (vec.size() <= 1)
        return;
    std::vector<int>::iterator it = vec.begin();
    std::vector<std::pair<int, int> > vecPairs;
    std::vector<int> vectorMain;
    int remain = -1;
    while (it != vec.end())
    {
        int first = *it;
        ++it;
        if (it != vec.end())
        {
            int second = *it;
            if (first > second)
                vecPairs.push_back(std::make_pair(second, first));
            else
                vecPairs.push_back(std::make_pair(first, second));
            ++it;
        }
        else
        {
            remain = first;
        }
    }
    for (std::vector<std::pair<int, int> >::iterator it = vecPairs.begin(); it != vecPairs.end(); ++it)
    {
        vectorMain.push_back(it->second);
    }
    sortVector(vectorMain);
    for (std::vector<std::pair<int, int> >::iterator it = vecPairs.begin(); it != vecPairs.end(); ++it)
    {
        std::vector<int>::iterator pos = std::lower_bound(vectorMain.begin(), vectorMain.end(), it->first);
        vectorMain.insert(pos, it->first);
    }
    if (remain != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(vectorMain.begin(), vectorMain.end(), remain);
        vectorMain.insert(pos, remain);
    }
    vec = vectorMain;
}

void PmergeMe::sortDeque(std::deque<int>& deq)
{
    if (deq.size() <= 1)
        return;
    std::deque<int>::iterator it = deq.begin();
    std::deque<std::pair<int, int> > deqPairs;
    std::deque<int> deqMain;
    int remain = -1;
    while (it != deq.end())
    {
        int first = *it;
        ++it;
        if (it != deq.end())
        {
            int second = *it;
            if (first > second)
                deqPairs.push_back(std::make_pair(second, first));
            else
                deqPairs.push_back(std::make_pair(first, second));
            ++it;
        }
        else
        {
            remain = first;
        }
    }
    for (std::deque<std::pair<int, int> >::iterator it = deqPairs.begin(); it != deqPairs.end(); ++it)
    {
        deqMain.push_back(it->second);
    }
    sortDeque(deqMain);
    for (std::deque<std::pair<int, int> >::iterator it = deqPairs.begin(); it != deqPairs.end(); ++it)
    {
        std::deque<int>::iterator pos = std::lower_bound(deqMain.begin(), deqMain.end(), it->first);
        deqMain.insert(pos, it->first);
    }
    if (remain != -1)
    {
        std::deque<int>::iterator pos = std::lower_bound(deqMain.begin(), deqMain.end(), remain);
        deqMain.insert(pos, remain);
    }
    deq = deqMain;
}

