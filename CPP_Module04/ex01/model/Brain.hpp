#include <iostrem>
#include <string>


#ifndef BRAIN_HPP
#define BRAIN_HPP


class Brain 
{
    private:
        std::string ideas[100];
    private:
        Brain();
        Brain(const Brain &other);
        Brain &operator=(const Brain &other);
        ~Brain();
};

#endif