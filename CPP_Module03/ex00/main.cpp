/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:41:03 by oissa             #+#    #+#             */
/*   Updated: 2025/09/12 14:04:51 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

int main ()
{
    ClapTrap a("Omar");
    ClapTrap b("Enemy");

    a.attack("Enemy");

    b.takeDamage(3);

    a.beRepaired(2);

    for (int i = 0; i < 11; i++)
        a.attack("Enemy");

    a.takeDamage(20);

    a.beRepaired(5);

    return 0;

}
