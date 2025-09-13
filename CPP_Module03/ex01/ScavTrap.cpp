#include <string>
#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    name = "";
    hitPoints = 100;
    energyPoint = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(std::string n) : ClapTrap(n)
{
    std::cout << "ScavTrap constructor called for " << n << std::endl;
    hitPoints = 100;
    energyPoint = 50;
    attackDamage = 20;
}
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called for " << name << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode!" << std::endl;
}
void ScavTrap::attack(const std::string &target)
{
    if (energyPoint > 0 && hitPoints > 0)
    {
        std::cout << "ScavTrap " << name 
                  << " fiercely attacks " << target 
                  << ", causing " << attackDamage 
                  << " points of damage!" << std::endl;
        energyPoint--;
    }
    else
    {
        std::cout << "ScavTrap " << name 
            << " has no energy or hit points left to attack!" 
            << std::endl;
    }
}