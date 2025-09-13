#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    name = "";
    hitPoints = 100;
    energyPoint = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const std::string &n) : ClapTrap(n)
{
    std::cout << "FragTrap constructor called for " << n << std::endl;
    hitPoints = 100;
    energyPoint = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for " << name << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}