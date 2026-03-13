/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 20:20:30 by gkambarb          #+#    #+#             */
/*   Updated: 2026/03/13 15:06:30 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream> 
#include <cmath> // for roundf

// default constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fp_num = 0;
}

// constructor
Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->fp_num = n << frac_bits; // Shift left to store as fixed-point
}

// constructor
Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->fp_num = static_cast<int>(roundf(f * (1 << frac_bits))); // Convert to fixed-point
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
	return (this->fp_num);
}

// Set raw value of fixed
void Fixed::setRawBits (int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fp_num = raw;
}

// Convert fixed to float
float Fixed::toFloat( void ) const
{
	// Divide by 256 to get the float value
	return (static_cast<float>(this->fp_num) / (1 << frac_bits)); 
}

// Convert fixed to int
int Fixed::toInt( void ) const
{
	// Shift right to get the integer part
	return (this->fp_num >> frac_bits);
}

// Overload insertion (<<) operator for Fixed class
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}




