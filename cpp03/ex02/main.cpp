/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 18:53:55 by gkambarb          #+#    #+#             */
/*   Updated: 2026/03/18 18:53:57 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "=== ClapTrap Construction ===" << std::endl;
    ClapTrap a("Aaaaand");

    std::cout << std::endl << "=== ScavTrap Construction ===" << std::endl;
    ScavTrap s("Saaaand");

    std::cout << std::endl << "=== FragTrap Construction ===" << std::endl;
    FragTrap f("Faaaand");

    std::cout << std::endl << "=== ClapTrap Attack ===" << std::endl;
    a.attack("Faaaand");

    std::cout << std::endl << "=== ScavTrap Attack ===" << std::endl;
    s.attack("Faaaand");

    std::cout << std::endl << "=== FragTrap Attack ===" << std::endl;
    f.attack("Saaaand");

    std::cout << std::endl << "=== FragTrap Damage ===" << std::endl;
    f.takeDamage(40);
    f.takeDamage(50);

    std::cout << std::endl << "=== FragTrap Repair ===" << std::endl;
    f.beRepaired(25);

    std::cout << std::endl << "=== ScavTrap Guard Gate ===" << std::endl;
    s.guardGate();

    std::cout << std::endl << "=== FragTrap High Fives ===" << std::endl;
    f.highFivesGuys();

    std::cout << std::endl << "=== Destruction ===" << std::endl;
    return 0;
}
