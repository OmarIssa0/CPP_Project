/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:41:03 by oissa             #+#    #+#             */
/*   Updated: 2025/08/30 16:28:13 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>
#include <string>

int main()
{
    ScavTrap s("OmarBot");

    s.attack("target");
    s.guardGate();
}
