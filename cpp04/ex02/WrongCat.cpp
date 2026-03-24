/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 12:57:56 by gkambarb          #+#    #+#             */
/*   Updated: 2026/03/21 12:57:58 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(), brain(new Brain())
{
    type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    brain = other.brain;  // SHALLOW: copies pointer, not the Brain itself
    std::cout << "WrongCat copy constructor called (SHALLOW!)" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat copy assignment operator called (SHALLOW!)" << std::endl;
    if (this != &other)
    {
        WrongAnimal::operator=(other);
        brain = other.brain;  // SHALLOW: copies pointer, not the Brain itself
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
    delete brain;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat: Meow! Meow!" << std::endl;
}
