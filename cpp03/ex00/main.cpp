/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 18:50:31 by gkambarb          #+#    #+#             */
/*   Updated: 2026/03/18 18:50:32 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    std::cout << "=== Construction ===" << std::endl;
    ClapTrap a("Aaaaand");
    ClapTrap b("Baaaand");

    std::cout << std::endl << "=== Attack ===" << std::endl;
    a.attack("Baaaand");

    std::cout << std::endl << "=== Damage ===" << std::endl;
    b.takeDamage(5);
    b.takeDamage(3);

    std::cout << std::endl << "=== Repair ===" << std::endl;
    b.beRepaired(4);

    std::cout << std::endl << "=== Disable ===" << std::endl;
    b.takeDamage(20);
    b.takeDamage(1);
    b.beRepaired(5);

    std::cout << std::endl << "=== Energy drain ===" << std::endl;
    ClapTrap c("Caaaand");
    for (int i = 0; i < 20; i++)
        c.attack("target");

    std::cout << std::endl << "=== Copy ===" << std::endl;
    ClapTrap d(a);
    ClapTrap e;
    e = a;

    std::cout << std::endl << "=== Destruction ===" << std::endl;
    return 0;
}
