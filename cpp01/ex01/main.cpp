/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:30:00 by gkambarb          #+#    #+#             */
/*   Updated: 2026/01/26 18:45:04 by gkambarb         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"

int main()
{
    int N = 10;
    
    Zombie* horde = zombieHorde(N, "Zombie");
    if (horde == NULL)
    {
        std::cout << "Error: Failed to create zombie horde." << std::endl;
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        horde[i].announce();
    }
    
    delete[] horde;
    return 0;
}
