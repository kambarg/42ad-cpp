/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:02:11 by gkambarb          #+#    #+#             */
/*   Updated: 2025/11/04 09:14:55 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

int main(int argc, char **argv) 
{
    if (argc == 1) 
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    } 
    else 
    {
        for (int i = 1; i < argc; i++) 
        {
            std::string str = argv[i];
            for (size_t j = 0; j < str.length(); j++) 
            {
                std::cout << (char)std::toupper(str[j]);
            }
        }
        std::cout << std::endl;
    }
    return 0;
}