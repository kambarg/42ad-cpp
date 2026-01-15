/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:06:55 by gkambarb          #+#    #+#             */
/*   Updated: 2026/01/16 03:14:34 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Constructor
HumanA::HumanA(const std::string& humanName, Weapon& humanWeapon)
    : name(humanName), weapon(humanWeapon) 
{}

// Destructor
HumanA::~HumanA() 
{}

// Member function
void HumanA::attack() const 
{
  std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}