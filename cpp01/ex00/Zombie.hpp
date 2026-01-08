/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:11:30 by gkambarb          #+#    #+#             */
/*   Updated: 2026/01/08 14:32:46 by gkambarb         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
  private:
    std::string name;
    
  public:
    Zombie();
    ~Zombie();

    void announce( void );
    void setName( std::string name );
};

Zombie* newZombie( std::string given_name );
void randomChump( std::string given_name );

#endif