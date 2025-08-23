/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:22:37 by oissa             #+#    #+#             */
/*   Updated: 2025/08/22 20:18:23 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
Fixed::Fixed() : _fixedValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// ? << left shift (value * 256) = (value << 8)
// ? example: Fixed(10)
Fixed::Fixed(int value) : _fixedValue(value << _fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

// ? (1 << _fractionalBits) --> (1 << 8 = (256))
// ? value * (1 << _fractionalBits) -> 42.42 * 256 = 10859.52
// ? roundf(10859.52) = 10860
// ? static_cast<int>(10860.0) = 10860
Fixed::Fixed(float value) : _fixedValue(static_cast<int>(roundf(value * (1 << _fractionalBits))))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _fixedValue(other._fixedValue)
{
    std::cout << "Copy constructor called" << std::endl;
}

// ? Fixed a;
// ? Fixed b = a;
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _fixedValue = other._fixedValue;
    return *this;
}

Fixed::~Fixed()
{
    std :: cout << "Destructor called" << std::endl;
}

int Fixed::toInt() const
{
    return (_fixedValue / 256); // ? or _fixedValue >> _fractionalBits
}

float Fixed::toFloat() const
{
    return (static_cast<float>(_fixedValue) / (1 << _fractionalBits));
}

// ? Fixed a(10);
// ? Fixed b(42.42f);
// ? std::cout << a << " " << b << std::endl;
std::ostream& operator<<(std::ostream &os, Fixed const &obj)
{
    return os << obj.toFloat(); 
}