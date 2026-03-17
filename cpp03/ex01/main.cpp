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

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== ClapTrap Construction ===" << std::endl;
    ClapTrap a("Aaaaand");

    std::cout << std::endl << "=== ScavTrap Construction ===" << std::endl;
    ScavTrap s("Saaaand");

    std::cout << std::endl << "=== ClapTrap Attack ===" << std::endl;
    a.attack("Saaaand");

    std::cout << std::endl << "=== ScavTrap Attack ===" << std::endl;
    s.attack("Aaaaand");

    std::cout << std::endl << "=== ScavTrap Damage ===" << std::endl;
    s.takeDamage(30);
    s.takeDamage(50);

    std::cout << std::endl << "=== ScavTrap Repair ===" << std::endl;
    s.beRepaired(20);

    std::cout << std::endl << "=== ScavTrap Guard Gate ===" << std::endl;
    s.guardGate();

    std::cout << std::endl << "=== Destruction ===" << std::endl;
    return 0;
}
