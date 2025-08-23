/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:42:51 by oissa             #+#    #+#             */
/*   Updated: 2025/08/22 20:48:02 by oissa            ###   ########.fr       */
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
        // ! int getRawBits() const;
        // ! void setRawBits(int raw);
};

/* 
    * extern (ostream) cout: ostream class
    ? ostream& -> std::cout << a << b
    ? operator<< -> operator(cout, a) ---> result: cout << a
*/
std::ostream& operator<<(std::ostream &os, Fixed const &obj); 

#endif