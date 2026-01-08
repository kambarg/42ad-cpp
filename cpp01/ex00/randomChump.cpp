/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:58:46 by gkambarb          #+#    #+#             */
/*   Updated: 2026/01/08 14:30:58 by gkambarb         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"

void randomChump( std::string given_name )
{
    Zombie zombie;
    zombie.setName(given_name);
    zombie.announce();
}
