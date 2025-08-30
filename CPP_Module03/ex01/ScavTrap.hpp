#include "iostream"
#include "string"
#include "ClapTrap.hpp"

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

class ScavTrap: public ClapTrap
{
    public: 
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &other);
        ScavTrap &operator=(const ScavTrap &other);
        ~ScavTrap();
        void guardGate();
        // ! Override (attack)
        void attack(const std::string &target);
};

#endif