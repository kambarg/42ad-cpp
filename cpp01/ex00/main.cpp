/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:58:08 by gkambarb          #+#    #+#             */
/*   Updated: 2026/01/12 12:09:45 by gkambarb         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

# include "Zombie.hpp"

int main(void)
{
    // Creating Zombie on the stack
    Zombie zombie0( "Zombie Null" );
    zombie0.announce();

    // Creating Zombie on the stack
    randomChump( "Zombie Stack" );

    // Creating Zombie on the heap
    Zombie* zombie1 = newZombie( "Zombie Heap" );
    zombie1->announce();
    delete zombie1;
}