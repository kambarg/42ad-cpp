/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:13:29 by gkambarb          #+#    #+#             */
/*   Updated: 2026/01/16 02:10:09 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

int main()
{
    Weapon club = Weapon("default club");
    std::cout << "Initial value: " << club.getType() << std::endl;
    club.setType ("new type of club");
    std::cout << "Assinged new value: " << club.getType() << std::endl;
    
    // {
    //     Weapon club = Weapon("crude spiked club");
    //     HumanA bob("Bob", club);
    //     bob.attack();
    //     club.setType("some other type of club");
    //     bob.attack();
    // }
    // {
    //     Weapon club = Weapon("crude spiked club");
    //     HumanB jim("Jim");
    //     jim.setWeapon(club);
    //     jim.attack();
    //     club.setType("some other type of club");
    //     jim.attack();
    // }
    return 0;
}