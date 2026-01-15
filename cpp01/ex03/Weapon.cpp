/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:26:30 by gkambarb          #+#    #+#             */
/*   Updated: 2026/01/16 01:37:34 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Constructor
Weapon::Weapon(const std::string &initialType) : type(initialType) 
{}

// Destructor
Weapon::~Weapon() 
{}

// Member Functions
const std::string& Weapon::getType() const 
{ 
    return type; 
}

void Weapon::setType(const std::string& newType) 
{ 
    type = newType; 
}