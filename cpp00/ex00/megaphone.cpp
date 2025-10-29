/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:02:11 by gkambarb          #+#    #+#             */
/*   Updated: 2025/10/29 17:30:04 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

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
            for (int j = 0; argv[i][j] != '\0'; j++) 
            {
                std::cout << (char)std::toupper(argv[i][j]);
            }
        }
        std::cout << std::endl;
    }
    return 0;
}