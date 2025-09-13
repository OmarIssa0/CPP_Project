#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

#ifndef CAT_HPP
#define CAT_HPP

class Cat : public Animal
{
    private:
        Brain *brain;
    public:
        Cat();
        Cat(const Cat &other);
        Cat &operator=(const Cat &other);
        ~Cat();
        // ! override 
        void makeSound () const;
        Brain *getBrain() const;
};

#endif