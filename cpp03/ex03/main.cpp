/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 12:00:00 by gkambarb          #+#    #+#             */
/*   Updated: 2026/03/15 12:00:00 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    std::cout << "=== DiamondTrap Construction ===" << std::endl;
    DiamondTrap d("Daaaand");

    std::cout << std::endl << "=== Who Am I ===" << std::endl;
    d.whoAmI();

    std::cout << std::endl << "=== DiamondTrap Attack (uses ScavTrap) ===" << std::endl;
    d.attack("target");

    std::cout << std::endl << "=== DiamondTrap Damage ===" << std::endl;
    d.takeDamage(40);

    std::cout << std::endl << "=== DiamondTrap Repair ===" << std::endl;
    d.beRepaired(15);

    std::cout << std::endl << "=== DiamondTrap Special Abilities ===" << std::endl;
    d.guardGate();
    d.highFivesGuys();

    std::cout << std::endl << "=== Destruction ===" << std::endl;
    return 0;
}
