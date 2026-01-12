/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:11:30 by gkambarb          #+#    #+#             */
/*   Updated: 2026/01/12 14:46:47 by gkambarb         ###   ########.fr       */
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
    Zombie( std::string input_name );
    ~Zombie();

    void announce( void );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif