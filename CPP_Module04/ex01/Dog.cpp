#include "Dog.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

Dog::Dog() : Animal("Dog")
{
    brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    brain = new Brain(*other.brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Dog copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}

Brain *Dog::getBrain() const
{
    return brain;
}