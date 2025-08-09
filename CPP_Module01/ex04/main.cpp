/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:57:24 by oissa             #+#    #+#             */
/*   Updated: 2025/07/26 16:57:24 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

std ::string replaceString(const std::string &str, const std::string &s1, const std::string &s2)
{
    std::string result;
    size_t pos = 0;
    size_t prev = 0;
    while ((pos = str.find(s1, prev)) != std::string::npos)
    {
        result += str.substr(prev, pos - prev);
        result += s2;
        prev = pos + s1.length();
    }
    result += str.substr(prev);
    return result;
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage: " << av[0] << " <filename> <string_to_replace> <replacement_string>" << std::endl;
        return 1;
    }
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    if (s1.empty())
    {
        std::cerr << "Error: The string to replace cannot be empty." << std::endl;
        return 1;
    }

    std::ifstream infile(filename.c_str());
    if (!infile.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }
    std::string content;
    std::string line;
    while (std::getline(infile, line))
    {
        content += line + "\n";
    }
    infile.close();

    std::string replacedContent = replaceString(content, s1, s2);
    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Error: Could not create file " << filename + ".replace" << std::endl;
        return 1;
    }
    outfile << replacedContent;
    outfile.close();
    return 0;
}