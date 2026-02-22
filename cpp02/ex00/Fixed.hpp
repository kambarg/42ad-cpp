/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 20:20:26 by gkambarb          #+#    #+#             */
/*   Updated: 2026/02/22 20:37:11 by gkambarb         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int fp_num;
		static const int frac_bits = 8;

	public:
		Fixed(); // default constructor
		~Fixed(); // destructor
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );		

};

#endif