/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:33:42 by gkambarb          #+#    #+#             */
/*   Updated: 2026/01/19 14:02:36 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA
{
    private:
        std::string name;
        Weapon& weapon;

    public:
        HumanA(const std::string& humanName, Weapon& humanWeapon);
        ~HumanA();

  void attack() const;
};

#endif