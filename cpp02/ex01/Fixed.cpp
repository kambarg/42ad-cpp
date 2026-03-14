/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 20:20:30 by gkambarb          #+#    #+#             */
/*   Updated: 2026/03/14 11:42:56 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream> 
#include <cmath> // for roundf

// In Fixed class fp_num = [int part (upper bits)].[fractional part (8 bits)]
// Convert int->fixed  n << 8 bits 
// Convert fixed->int  n >> 8 bits 
// Convert float->fixed roundf(f * (1 << 8))
// Convert fixed->float (fp_num / (1 << 8)) = fp_num / 2^8 = fp_num / 256 

// default constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fp_num = 0;
}

// int constructor
Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->fp_num = n << frac_bits;
}

// float constructor
Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->fp_num = static_cast<int>(roundf(f * (1 << frac_bits)));
}

// copy constructor
Fixed::Fixed (const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl; 
	*this = other;  // Calls assignment operator
	// this->fp_num = other.getRawBits(); // Without calling assignment operator
}

// copy assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout <<"Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->fp_num = other.getRawBits();
	}
	return *this;
}

// destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Return the raw value of fixed
int Fixed::getRawBits( void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fp_num);
}

// Set raw value of fixed
void Fixed::setRawBits (int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fp_num = raw;
}

// Convert fixed to int
int Fixed::toInt( void ) const
{
	return (this->fp_num >> frac_bits);
}

// Convert fixed to float
float Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->fp_num) / (1 << frac_bits)); 
}

// Overload insertion (<<) operator for Fixed objects
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}
