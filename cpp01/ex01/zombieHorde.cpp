/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:52:56 by gkambarb          #+#    #+#             */
/*   Updated: 2026/01/15 23:13:41 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N <= 0)
        return NULL;
    
    // Allocate N zombies in a single allocation
    Zombie* horde = new Zombie[N];
    
    // Initialize each zombie with the given name
    for (int i = 0; i < N; i++)
    {
        std::stringstream ss;
        ss << name << "_" << i;
        horde[i].setName(ss.str());
    }
    
    return horde;
}