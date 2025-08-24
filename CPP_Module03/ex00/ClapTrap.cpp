/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:39:30 by oissa             #+#    #+#             */
/*   Updated: 2025/08/24 21:12:10 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitPoints(10) , energyPoint(10), attackDamage(0), name("") {}

ClapTrap::ClapTrap(const ClapTrap &other) : hitPoints(other.hitPoints),
    energyPoint(other.energyPoint), attackDamage(other.attackDamage) 
{
    std::cout << "Copy constructor called" << std::endl;
} 

ClapTrap &ClapTrap::operator=(const ClapTrap &other) 
{
    if (this != other)
    {
        this->hitPoints = other.hitPoints;
        this->energyPoint = other.energyPoint;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {}

void ClapTrap::attack(const std::string &target)
{
    this->energyPoint -= 
}

void ClapTrap::takeDamage(unsigned int amount)
{
    
}

void ClapTrap::beRepaired(unsigned int amount)
{
    
}