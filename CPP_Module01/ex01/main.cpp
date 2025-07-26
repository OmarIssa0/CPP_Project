/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:12:45 by oissa             #+#    #+#             */
/*   Updated: 2025/07/25 21:12:45 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"
#include <iostream>
#include <string>

int main()
{
    Zombie* horde = zombieHorde(5, "Zombie");
    for (int i = 0; i < 5; i++) {
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}