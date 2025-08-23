/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:42:51 by oissa             #+#    #+#             */
/*   Updated: 2025/08/23 18:06:41 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef FIXED_HPP
#define FIXED_HPP
class Fixed
{
private:
    int _fixedValue;
    static const int _fractionalBits = 8;

public:
    Fixed();
    Fixed(int value);
    Fixed(float value);
    ~Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    float toFloat() const;
    int toInt() const;
    int getRawBits() const;
    void setRawBits(int raw);
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;
    Fixed &operator++();   // pre
    Fixed operator++(int); // post
    Fixed &operator--();
    Fixed operator--(int);
    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};
/*
    * extern (ostream) cout: ostream class
    ? ostream& -> std::cout << a << b
    ? operator<< -> operator(cout, a) ---> result: cout << a
*/
std::ostream &operator<<(std::ostream &os, Fixed const &obj);

#endif