/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:52:56 by gkambarb          #+#    #+#             */
/*   Updated: 2026/01/26 18:49:44 by gkambarb         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"
#include <sstream>

Zombie *zombieHorde(int N, std::string name) 
{
  if (N <= 0 || N >= 10000)
  {
    std::cout << "Cannot create horde: N must be greater than 0 and less than 10000." << std::endl; 
    return NULL;
  }
  
  Zombie *horde = new Zombie[N];

  for (int i = 0; i < N; i++) {
    std::stringstream ss;
    ss << name << "_" << i;
    horde[i].setName(ss.str());
  }

  return horde;
}