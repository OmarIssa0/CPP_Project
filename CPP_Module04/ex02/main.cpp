#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include <string>
#include <iostream>

int main()
{
    std::cout << "=== Testing Abstract Animal Class ===" << std::endl;
    Animal *animals[6];
    std::cout << "Creating 3 Dogs..." << std::endl;
    for (int i = 0; i < 3; ++i)
        animals[i] = new Dog();
    std::cout << "Creating 3 Cats..." << std::endl;
    for (int i = 3; i < 6; ++i)
        animals[i] = new Cat();

    std::cout << "Making sounds..." << std::endl;
    for (int i = 0; i < 6; ++i)
        animals[i]->makeSound();

    std::cout << "Destructing all..." << std::endl;
    for (int i = 0; i < 6; ++i)
        delete animals[i];
    // Animal* animal = new Animal(); // not allowed because there is pure virtual function
    std::cout << "================= DEEP COPY CAT TEST ========" << std::endl;
    Cat *originalCat = new Cat();
    originalCat->getBrain()->setData(0, "From Original: Chase the mouse first");
    originalCat->getBrain()->setData(1, "From Original: Chase the mouse second");
    originalCat->getBrain()->setData(2, "From Original: Chase the mouse third");
    originalCat->getBrain()->setData(3, "From Original: Chase the mouse fourth");
    originalCat->getBrain()->setData(4, "From Original: Chase the mouse fifth");
    originalCat->getBrain()->setData(5, "From Original: Chase the mouse sixth");
    originalCat->getBrain()->setData(6, "From Original: Chase the mouse seventh");
    Cat *copyCat = new Cat(*originalCat);
    copyCat->getBrain()->setData(4, "From Copy: Sleep all day");
    copyCat->getBrain()->setData(10, "From Copy: Sleep all night");
    copyCat->getBrain()->setData(9, "From Copy: Sleep in the afternoon");
    copyCat->getBrain()->setData(3, "From Copy: Sleep on the couch");
    copyCat->getBrain()->setData(4, "From Copy: Sleep on the bed");
    Cat *assignEqualCat = new Cat();
    *assignEqualCat = *originalCat;
    assignEqualCat->getBrain()->setData(0, "From assignment: Play with yarn");
    for (int i = 0; i < 11; i++)
        std::cout << "Original Cat Idea[" << i << "]: " << originalCat->getBrain()->getData(i) << std::endl;
    std::cout << "====================================================== " << std::endl;
    for (int i = 0; i < 11; i++)
        std::cout << "Copied Cat Idea[" << i << "]: " << copyCat->getBrain()->getData(i) << std::endl;
    std::cout << "====================================================== " << std::endl;
    for (int i = 0; i < 11; i++)
        std::cout << "Assignment Cat IDeas[" << i << "]: " << assignEqualCat->getBrain()->getData(i) << std::endl;
    std::cout << "====================================================== " << std::endl;
    std::cout << "================= End of Deep Copy Test ========" << std::endl;

    delete originalCat;
    delete copyCat;
    delete assignEqualCat;
    return 0;
}