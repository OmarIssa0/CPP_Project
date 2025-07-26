/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:00:58 by oissa             #+#    #+#             */
/*   Updated: 2025/07/25 20:00:58 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"
#include <iostream>
#include <string>

int main()
{
    Zombie* zombie1 = newZombie("Zombie1");
    zombie1->announce();
    delete zombie1;
    randomChump("Zombie2");
    return (0);
}