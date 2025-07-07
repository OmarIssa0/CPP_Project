/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:16:05 by oissa             #+#    #+#             */
/*   Updated: 2025/06/20 20:16:05 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.h"
#include "PhoneBookClass.hpp"

PhoneBook::PhoneBook() : nextIndex(0) {}

void PhoneBook::addContact()
{
    contacts[nextIndex % 8].setContact();
    nextIndex = (nextIndex + 1) % 8;
    if (totalContacts < 8)
        totalContacts++;
}

void PhoneBook::searchContacts()
{
    if (totalContacts == 0)
    {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }
     std :: cout << "| " << std::setw(10) << "Index" 
              << " | " << std::setw(10) << "First Name" 
              << " | " << std::setw(10) << "Last Name" 
              << " | " << std::setw(10) << "Nickname" 
              << " |" << std::endl;
    std::cout << std::string(57, '-') << std::endl;
              // std::cout << "Search for a contact" << std::endl;
    for (int i = 0; i < totalContacts; i++)
    {
        contacts[i].displayShort(i);
    }
    std::cout << "Enter the index of the contact to display: ";
    std:: string input;
    std :: getline(std::cin, input);
    if (input.empty())
    {
        std::cout << "Input is empty. Aborting.\n";
        return;
    }
    for (size_t i = 0; i < input.length(); i++)
    {
        if (!std::isdigit(input[i]))
        {
            std:: cout << "Invalid input, Please enter a number." << std::endl;    
            return;
        }
    }
    int index = std::atoi(input.c_str());
    if (index >= 0 && index < totalContacts)
    {
        contacts[index].displayContact();
    }
    else
    {
        std::cout << "Invalid index!" << std::endl;
    }
}