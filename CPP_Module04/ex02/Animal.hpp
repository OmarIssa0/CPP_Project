/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:40:24 by oissa             #+#    #+#             */
/*   Updated: 2025/09/04 18:40:24 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const std::string &type);
        Animal(const Animal &other);
        Animal &operator=(const Animal &other);
        virtual ~Animal();
        virtual void makeSound() const = 0;
        std::string getType() const;
};

#endif 