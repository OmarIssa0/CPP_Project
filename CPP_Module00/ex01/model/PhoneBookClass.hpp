/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 19:57:35 by oissa             #+#    #+#             */
/*   Updated: 2025/06/20 19:57:35 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "../include/PhoneBook.h"
#include "ContactClass.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int nextIndex;
    int totalContacts;
    bool isError;

public:
    PhoneBook();
    void addContact();
    void searchContacts();
};

#endif