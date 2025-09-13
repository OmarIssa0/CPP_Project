#include <iostream>
#include <string>


#ifndef BRAIN_HPP
#define BRAIN_HPP


class Brain 
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain &other);
        Brain &operator=(const Brain &other);
        ~Brain();
        std::string &getData(int index);
        void setData(int index, const std::string &string);
};

#endif