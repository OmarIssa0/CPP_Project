/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:41:03 by oissa             #+#    #+#             */
/*   Updated: 2025/08/26 21:31:08 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

int main ()
{
    ClapTrap a("Omar");
    ClapTrap b("Enemy");

    // Omar attacks Enemy
    a.attack("Enemy");

    // Enemy takes damage
    b.takeDamage(3);

    // Omar repairs himself
    a.beRepaired(2);

    // استنزاف الطاقة
    for (int i = 0; i < 11; i++)
        a.attack("Enemy");

    // ضرب Omar ليموت
    a.takeDamage(20);

    // محاولة إصلاح وهو ميت
    a.beRepaired(5);

    return 0;

}
