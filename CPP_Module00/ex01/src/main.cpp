/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 20:35:42 by oissa             #+#    #+#             */
/*   Updated: 2025/06/20 20:35:42 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.h"
#include "../model/PhoneBookClass.hpp"

int main () 
{
    PhoneBook phone;
    std::string command;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (std::cin.eof())
        {
            std::cout << "\nEOF found, exit!" << std::endl;
            break;
        }
        if (command == "ADD")
            phone.addContact();
        else if (command == "SEARCH")
        {
            phone.searchContacts();
        }
        else if (command == "EXIT")
        {
            std::cout << "Exiting the program..." << std::endl;
            break;
        }
        else
            std::cout << "Invalid command. Please try again." << std::endl;
    }
    return 0;
}
