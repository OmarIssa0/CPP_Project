#include "iostream"
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

#ifndef DOG_HPP
#define DOG_HPP

class Dog : public Animal
{
    private:
        Brain *brain;
    public:
        Dog();
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);
        ~Dog();
        // ! override 
        void makeSound () const;
        Brain *getBrain() const;
};

#endif