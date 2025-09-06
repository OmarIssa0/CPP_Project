#include "../model/WrongCat.hpp"
#include "../model/WrongAnimal.hpp"
#include <string>
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") {}
WrongCat::~WrongCat() {}
void WrongCat::makeSound() const
{
    std::cout << "WrongCat" << std::endl;
}