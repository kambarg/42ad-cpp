/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:58:18 by gkambarb          #+#    #+#             */
/*   Updated: 2026/01/08 14:16:14 by gkambarb         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"

Zombie* newZombie( std::string given_name )
{
    Zombie* zombie = new Zombie();
    zombie->setName(given_name);
    return zombie;
}
