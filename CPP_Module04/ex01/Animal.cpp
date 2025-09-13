#include "Animal.hpp"
#include <string>
#include <iostream>

Animal::Animal() : type("") 
{
    std::cout << "Animal default constructor called" << std::endl;
}
Animal::Animal(const std::string &t) : type(t)
{
    std::cout << "Animal constructor called for " << t << std::endl;
}
Animal::Animal(const Animal &other) : type(other.type){}
Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}
Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Some animal sound" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}