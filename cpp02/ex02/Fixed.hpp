/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 20:20:26 by gkambarb          #+#    #+#             */
/*   Updated: 2026/03/14 14:03:58 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
 
// comparison, arithmetic, increment/decrement operators:
//  - Public member functios (belong to the object)
//  - operator overloading (same operator, diff parameters)

// min, max:
// - Public static (belong to the class, not object) member functions
// - function overloading (same function name, diff parameters)

// stream insertion operator (<<)
//  - Free function as returns reference to ostream& object
//  - operator overloading

class Fixed
{
	private:
		int fp_num;
		static const int frac_bits = 8;

	public:
		Fixed();                              // default constructor
		Fixed(const int n);                   // constructor int -> fixed
		Fixed(const float f);                 // constructor float -> fixed
		Fixed(const Fixed& other);            // Copy constructor
    	Fixed& operator=(const Fixed& other); // Copy assignment operator
		~Fixed();                             // destructor
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		int toInt( void ) const;
		float toFloat( void ) const;

		// Comparison operators
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		// Arithmetic operators
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		// Increment/Decrement operators
		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);

		// Min/Max static member functions
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};

// Stream insertion operator free function
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif