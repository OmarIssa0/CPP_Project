/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:29:44 by oissa             #+#    #+#             */
/*   Updated: 2025/06/20 20:29:44 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ContactClass.hpp"
#include <iomanip>

Contact::Contact()
{
    firstName = "";
    lastName = "";
    nickname = "";
    phoneNumber = "";
    darkestSecret = "";
}

void Contact::setContact()
{
    while (true)
    {
        std::cout << "Enter first name: ";
        std::getline(std::cin, firstName);
        bool notEmpty = !firstName.empty();
        size_t i = 0;
        while (i < firstName.length())
        {
            if (!std::isalpha(firstName[i]) && firstName[i] != ' ')
            {
                notEmpty = false;
                break;
            }
            i++;
        }
        if (notEmpty)
            break;
        else
            std::cout << "Invalid First Name" << std::endl;
    }
    while (true)
    {
        std::cout << "Enter last name: ";
        std::getline(std::cin, lastName);
        bool notEmpty = !lastName.empty();
        size_t i = 0;
        while (i < lastName.length())
        {
            if (!std::isalpha(lastName[i]) && lastName[i] != ' ')
            {
                notEmpty = false;
                break;
            }
            i++;
        }
        if (notEmpty)
            break;
        else
            std::cout << "Invalid Last Name" << std::endl;
    }
    while (true)
    {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, nickname);
        bool notEmpty = !nickname.empty();
        size_t i = 0;
        while (i < nickname.length())
        {
            if (!std::isalpha(nickname[i]) && nickname[i] != ' ')
            {
                notEmpty = false;
                break;
            }
            i++;
        }
        if (notEmpty)
            break;
        else
            std::cout << "Invalid nickname" << std::endl;
    }

    while (true)
    {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, phoneNumber);
        bool valid = phoneNumber.length() == 10;
        size_t i = 0;
        while (i < phoneNumber.length())
        {
            if (!std::isdigit(phoneNumber[i]))
            {
                valid = false;
                break;
            }
            i++;
        }
        if (valid)
            break;
        else
            std::cout << "Invalid Phone Number! It must be exactly 10 digits." << std::endl;
    }
    while (true)
    {
        std::cout << "Enter darkest secret:";
        std::getline(std::cin, darkestSecret);
        bool notEmpty = !darkestSecret.empty();
        size_t i = 0;
        while (i < darkestSecret.length())
        {
            if (!std::isalpha(darkestSecret[i]) && darkestSecret[i] != ' ')
            {
                notEmpty = false;
                break;
            }
            i++;
        }
        if (notEmpty)
            break;
        else
            std::cout << "Invalid darkest secret" << std::endl;
    }
}

void Contact::displayShort(int index)
{
    std::cout << "| " << std::setw(10) << index;

    std::string f = (firstName.length() > 10) ? firstName.substr(0, 9) + "." : firstName;
    std::cout << " | " << std::setw(10) << f;

    std::string l = (lastName.length() > 10) ? lastName.substr(0, 9) + "." : lastName;
    std::cout << " | " <<  std::setw(10) << l;

    std::string n = (nickname.length() > 10) ? nickname.substr(0, 9) + "." : nickname;
    std::cout << " | "  <<std::setw(10) << n << " |" << std::endl;
}

void Contact::displayContact()
{
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Darkest secret: " << darkestSecret << std::endl;
}