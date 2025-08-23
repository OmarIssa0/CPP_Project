/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:22:37 by oissa             #+#    #+#             */
/*   Updated: 2025/08/23 18:06:41 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _fixedValue(0) {}

// ? << left shift (value * 256) = (value << 8)
// ? example: Fixed(10)
Fixed::Fixed(int value) : _fixedValue(value << _fractionalBits) {}

// ? (1 << _fractionalBits) --> (1 << 8 = (256))
// ? value * (1 << _fractionalBits) -> 42.42 * 256 = 10859.52
// ? roundf(10859.52) = 10860
// ? static_cast<int>(10860.0) = 10860
Fixed::Fixed(float value) : _fixedValue(static_cast<int>(roundf(value * (1 << _fractionalBits)))) {}

Fixed::Fixed(const Fixed &other) : _fixedValue(other._fixedValue) {}

// ? Fixed a;
// ? Fixed b = a;
Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        _fixedValue = other._fixedValue;
    return *this;
}

Fixed::~Fixed() {}

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
std::ostream &operator<<(std::ostream &os, Fixed const &obj)
{
    return os << obj.toFloat();
}

int Fixed::getRawBits() const
{
    return _fixedValue;
}

void Fixed::setRawBits(int raw)
{
    _fixedValue = raw;
}

bool Fixed::operator>(const Fixed &other) const
{
    if (_fixedValue > other._fixedValue)
        return (true);
    return (false);
}

bool Fixed::operator<(const Fixed &other) const
{
    if (_fixedValue < other._fixedValue)
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed &other) const
{
    if (_fixedValue <= other._fixedValue)
        return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed &other) const
{
    if (_fixedValue >= other._fixedValue)
        return (true);
    return (false);
}

bool Fixed::operator==(const Fixed &other) const
{
    if (_fixedValue == other._fixedValue)
        return (true);
    return (false);
}

bool Fixed::operator!=(const Fixed &other) const
{
    if (_fixedValue != other._fixedValue)
        return (true);
    return (false);
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed &Fixed::operator++() // ? pre
{
    this->_fixedValue += 1;
    return *this;
}

Fixed Fixed::operator++(int) // ? post
{
    Fixed old = *this;
    operator++();
    return old;
}

Fixed &Fixed::operator--() // ? pre
{
    this->_fixedValue -= 1;
    return *this;
}

Fixed Fixed::operator--(int) // ? post
{
    Fixed old = *this;
    operator--();
    return old;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}