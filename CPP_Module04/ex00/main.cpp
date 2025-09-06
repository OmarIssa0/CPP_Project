#include <iostream>
#include <string>
#include "model/Dog.hpp"
#include "model/Cat.hpp"
#include "model/WrongAnimal.hpp"
#include "model/WrongCat.hpp"

int main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete  meta;
    delete  j;
    delete  i;

    std::cout << "--------------------------------------------" << std::endl;
    const WrongAnimal *k = new WrongCat();
    k->makeSound();
    delete k;
    
    return 0;
}