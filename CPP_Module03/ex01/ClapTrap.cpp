/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:39:30 by oissa             #+#    #+#             */
/*   Updated: 2025/09/05 17:17:12 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitPoints(10) , energyPoint(10), attackDamage(0), name("") 
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : hitPoints(10) , energyPoint(10), attackDamage(0), name(name) 
{
    std::cout << "ClapTrap constructor called for " << name << std::endl;
    // std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : hitPoints(other.hitPoints),
    energyPoint(other.energyPoint), attackDamage(other.attackDamage) 
{
    // std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) 
{
    if (this != &other)
    {
        this->hitPoints = other.hitPoints;
        this->energyPoint = other.energyPoint;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called for " << name << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (energyPoint <= 0 || hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " has on energy or hit points to attack!" << std::endl;
        return ;
    }
    energyPoint--;
    std::cout << "ClapTrap " << name << " attacks " << target
        << ", causing " << attackDamage << " points of damage" << std::endl; 
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " is already down" << std::endl;
        return;
    }
    hitPoints -= amount;
    if (hitPoints < 0)
        hitPoints = 0;
    std::cout << "ClapTrap " << name << " took " << amount << " damage! Remaining HP: "
        << hitPoints << std::endl;
}   

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoint <= 0 || hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " can't repair!\n";
        return;
    }
    energyPoint--;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " repairs itself for " << amount
        << " points! New HP: " << hitPoints << "\n";
}