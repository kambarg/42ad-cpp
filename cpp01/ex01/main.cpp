/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:30:00 by gkambarb          #+#    #+#             */
/*   Updated: 2026/01/13 10:04:37 by gkambarb         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"

int main()
{
    int N = 5;
    
    std::cout << "Creating a horde of " << N << " zombies..." << std::endl;
    Zombie* horde = zombieHorde(N, "Zombie");
    
    std::cout << "\nCalling announce() for each zombie:" << std::endl;
    for (int i = 0; i < N; i++)
    {
        horde[i].announce();
    }
    
    std::cout << "\nDeleting the zombie horde..." << std::endl;
    delete[] horde;
    
    std::cout << "\nDone!" << std::endl;
    return 0;
}
