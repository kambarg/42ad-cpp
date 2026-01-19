/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:18:04 by gkambarb          #+#    #+#             */
/*   Updated: 2026/01/19 14:16:18 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

// Constructor
HumanB::HumanB(const std::string& humanName)
    : name(humanName)
    , weapon(NULL)
{}

// Destructor
HumanB::~HumanB() 
{}

// Member functions
void HumanB::setWeapon(Weapon& humanWeapon)
{
    weapon = &humanWeapon;
}

void HumanB::attack() const
{
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType()
                  << std::endl;
    else
        std::cout << name << " has no weapon!" << std::endl;
}