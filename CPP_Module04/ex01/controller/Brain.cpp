#include <iostrem>
#include <string>
#include "../model/Brain.hpp"

Brain::Brain () : ideas(0) {}
Brain::Brain(const Brain &other) : ideas(other.ideas) {}
Brain &Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        this->ideas = other.ideas;
    }
    return *this;
}
Brain::~Brain()
{
    
}