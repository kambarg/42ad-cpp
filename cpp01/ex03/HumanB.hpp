/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:34:39 by gkambarb          #+#    #+#             */
/*   Updated: 2026/01/16 03:15:52 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB 
{
    private:
        std::string name;
        Weapon* weapon;

    public:
        HumanB(const std::string& humanName);
        ~HumanB();

        void setWeapon(Weapon& humanWeapon);
        void attack() const;
};

#endif