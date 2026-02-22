/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 20:20:30 by gkambarb          #+#    #+#             */
/*   Updated: 2026/02/22 23:36:03 by gkambarb         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Fixed.hpp"
#include <iostream>

// default constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fp_num = 0;
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

// other member functios
int Fixed::getRawBits( void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fp_num);
}

void Fixed::setRawBits (int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fp_num = raw;
}




