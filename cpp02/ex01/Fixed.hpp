/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 20:20:26 by gkambarb          #+#    #+#             */
/*   Updated: 2026/02/27 02:46:40 by gkambarb         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int fp_num;
		static const int frac_bits = 8;

	public:
		Fixed();                              // default constructor
		Fixed(const int n);                   // constructor
		Fixed(const float f);                 // constructor
		Fixed(const Fixed& other);            // Copy constructor
    	Fixed& operator=(const Fixed& other); // Copy assignment operator
		~Fixed();                             // destructor
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );		
		float toFloat( void ) const;
		int toInt( void ) const;

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif