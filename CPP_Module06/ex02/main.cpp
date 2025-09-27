#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    int r = std::rand() % 3;
    switch (r)
    {
    case 0:
        return new A();
    case 1:
        return new B();
    case 2:
        return new C();
    default:
        return NULL;
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
    {
        std::cout << "A" << std::endl;
        return;
    }
    if (dynamic_cast<B *>(p))
    {
        std::cout << "B" << std::endl;
        return;
    }
    if (dynamic_cast<C *>(p))
    {
        std::cout << "C" << std::endl;
        return;
    }
    std::cout << "Unknown Type" << std::endl;
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (...)
    {
    }

    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (...)
    {
    }

    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (...)
    {
    }
}

int main()
{
    Base *ptr = generate();
    identify(ptr);
    identify(*ptr);

    delete ptr;
    return 0;
}