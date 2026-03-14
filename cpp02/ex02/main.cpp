/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 20:20:22 by gkambarb          #+#    #+#             */
/*   Updated: 2026/03/14 15:12:08 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	// my test cases
	// std::cout << "---------------------" << std::endl;
	// std::cout << "My test cases:" << std::endl;
	// std::cout << "a="<< a << std::endl;
	// std::cout << "b=" << b<< std::endl;
	// std::cout << "a > b is " << (a > b ? "true" : "false") << std::endl;
	// std::cout << "a.operator>(b) is 0 if false and 1 if true: " << a.operator>(b) <<std::endl;
	// std::cout << std::endl;
	
	// std::cout << "min(a,b) is " << Fixed::min(a,b) << std::endl;
	// std::cout << std::endl;
	
	// std::cout << "a++ returns: " << a++ << std::endl;
	// std::cout << "a=" << a << std::endl;
	// std::cout << "++a=" << ++a << std::endl;
	// std::cout << "---------------------" << std::endl;
	
	return 0;
}