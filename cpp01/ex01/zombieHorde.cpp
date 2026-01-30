/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:52:56 by gkambarb          #+#    #+#             */
/*   Updated: 2026/01/30 11:11:33 by gkambarb         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Zombie.hpp"
#include <sstream>

Zombie *zombieHorde(int N, std::string name) 
{
  if (N <= 0)
  {
    std::cout << "Cannot create horde: N shouldn´t be negative or zero." << std::endl; 
    return NULL;
  }
  else if (N >= 1000000)
  {
    std::cout << "Cannot create horde: N is too large and may cause bad allocation." << std::endl; 
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