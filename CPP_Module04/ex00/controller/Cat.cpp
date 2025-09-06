#include "../model/Cat.hpp"
#include <string>
#include <iostream>

Cat::Cat() : Animal("Cat")
{
}
Cat::~Cat()
{
}
void Cat::makeSound() const
{
    std::cout << "Cat" << std::endl;
}