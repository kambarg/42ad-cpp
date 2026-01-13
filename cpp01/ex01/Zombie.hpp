/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:11:30 by gkambarb          #+#    #+#             */
/*   Updated: 2026/01/13 09:31:23 by gkambarb         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <sstream>

class Zombie
{
  private:
    std::string name;
    
  public:
    Zombie();
    ~Zombie();

    void announce( void );
    void setName( std::string input_name );
};

Zombie* zombieHorde( int N, std::string name );

#endif