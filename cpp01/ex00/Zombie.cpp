/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:48:16 by gkambarb          #+#    #+#             */
/*   Updated: 2026/01/15 23:53:41 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor
Zombie::Zombie( std::string inputName ) : name(inputName)
{}

// Destructor
Zombie::~Zombie()
{
    std::cout << this->name << " has been destroyed." << std::endl;
}

// Member Functions
void Zombie::announce( void )
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}