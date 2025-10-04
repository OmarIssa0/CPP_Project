#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::cout << "--------------- vector ----------------" << std::endl;
    std::vector<int> num;
    num.push_back(10);
    num.push_back(20);
    num.push_back(30);
    num.push_back(42);
    try
    {
        std::vector<int>::iterator it = easyfind(num, 42);
        std::cout << "Value found: " << *it << std::endl;
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------- List ----------------" << std::endl;
    std::list<int> myList;
    myList.push_front(10);
    myList.push_front(20);
    myList.push_front(30);
    myList.push_front(40);
    try
    {
        std::list<int>::iterator it = easyfind(myList, 42);
        std::cout << "Value found: " << *it << std::endl;
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }


    std::cout << "--------------- vector (empty) ----------------" << std::endl;
    std::vector<int> numEmpty;
    try
    {
        std::vector<int>::iterator it = easyfind(numEmpty, -42);
        std::cout << "Value found: " << *it << std::endl;
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------- List (empty) ----------------" << std::endl;
    std::list<int> myListEmpty;
    try
    {
        std::list<int>::iterator it = easyfind(myListEmpty, 42);
        std::cout << "Value found: " << *it << std::endl;
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}
