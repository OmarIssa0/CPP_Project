#include "../model/Dog.hpp"
#include <string>
#include <iostream>


Dog::Dog() : Animal("Dog")
{}
Dog::~Dog() {}
void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}