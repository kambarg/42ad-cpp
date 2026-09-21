/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 10:39:16 by gkambarb          #+#    #+#             */
/*   Updated: 2026/09/21 15:07:05 by gkambarb         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./convert <literal>\n";
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}