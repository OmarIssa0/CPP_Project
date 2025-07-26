/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:35:46 by oissa             #+#    #+#             */
/*   Updated: 2025/07/25 20:35:46 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(std::string name) : name(name) 
{
    std::cout << name << " has been created." << std::endl;
}

Zombie::~Zombie() 
{
    std::cout << name << " has been destroyed." << std::endl;
}

void Zombie::announce() const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
