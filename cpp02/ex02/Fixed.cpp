/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 20:20:30 by gkambarb          #+#    #+#             */
/*   Updated: 2026/03/14 14:56:44 by gkambarb         ###   ########.fr       */
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

// int constructor
Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->fp_num = n << frac_bits; // Shift left to store as fixed-point
}

// float constructor
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
	std::cout << "getRawBits member function called" << std::endl;
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
	return (static_cast<float>(this->fp_num) / (1 << frac_bits)); 
}

// Convert fixed to int
int Fixed::toInt( void ) const
{
	return (this->fp_num >> frac_bits);
}

// Comparison operators
// n << 8 <=> n*256 => same order for positive and negative nums
bool Fixed::operator>(const Fixed& other) const
{
	return (this->fp_num > other.fp_num);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->fp_num < other.fp_num);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->fp_num >= other.fp_num);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->fp_num <= other.fp_num);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->fp_num == other.fp_num);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->fp_num != other.fp_num);
}

// Arithmetic operators
// a.fp_num + b.fp_num = (a*256) + (b*256) = (a+b)*256
Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.fp_num = this->fp_num + other.fp_num;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.fp_num = this->fp_num - other.fp_num;
	return result;
}

// a.fp_num * b.fp_num = (a*256) * (b*256) = (a*b)*256*256 - need only one 256
// => divide by 256 <=> (>> 8 bits)
// static_cast<long> is room for intermediate calculations
Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result.fp_num = static_cast<int>((static_cast<long>(this->fp_num) * other.fp_num) >> frac_bits);
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	result.fp_num = static_cast<int>((static_cast<long>(this->fp_num) << frac_bits) / other.fp_num);
	return result;
}

// fp_num=0, represented value=0/256=0
// fp_num++ => fp_num=1, rep_value=1/256=0.00390625 (epsilon)
// ...

// Pre-increment: ++x
Fixed& Fixed::operator++(void)
{
	this->fp_num++;
	return *this;
}

// Post-increment: x++
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->fp_num++;
	return temp;
}

// Pre-decrement: --x
Fixed& Fixed::operator--(void)
{
	this->fp_num--;
	return *this;
}

// Post-decrement: x--
Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->fp_num--;
	return temp;
}

// Min/Max static member functions
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

// Overload insertion (<<) operator for Fixed objects
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}
