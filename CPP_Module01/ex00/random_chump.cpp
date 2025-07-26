/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_chump.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:41:12 by oissa             #+#    #+#             */
/*   Updated: 2025/07/25 20:41:12 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"
#include <iostream>
#include <string>

void randomChump(std::string name) {
    Zombie zombie(name);
    zombie.announce();
}
