/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:06:41 by oissa             #+#    #+#             */
/*   Updated: 2025/04/30 18:06:41 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int check_alpha(int c)
{
    if (c >= 'a' && c <= 'z')
        return (EXIT_SUCCESS);
    return (EXIT_FAILURE);
}

int main (int ac, char **av)
{
    if (ac == 1)
    {
        std :: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std :: endl;
        return (EXIT_FAILURE);
    }
    int i = 0; // ! --> char
    int j = 1; // ! --> char *
    while (av[j])
    {
        i = 0;
        while (av[j][i])
        {
            if (check_alpha(av[j][i]) == EXIT_SUCCESS)
            {
                av[j][i] -= 32;
                std :: cout << av[j][i];
            }
            else
                std :: cout << av[j][i];
            i++;
        }
        j++;
    }
    return (EXIT_SUCCESS);
}