/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:26:25 by gkambarb          #+#    #+#             */
/*   Updated: 2026/01/16 03:26:43 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
private:
  std::string type;

public:
  Weapon(const std::string &initialType);
  ~Weapon();

  const std::string &getType() const;
  void setType(const std::string &newType);
};

#endif