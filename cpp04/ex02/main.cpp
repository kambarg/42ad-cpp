/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 00:34:52 by gkambarb          #+#    #+#             */
/*   Updated: 2026/03/30 02:24:36 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // Animal is now abstract — this would NOT compile:
    // const Animal* meta = new Animal();

    std::cout << "=== Abstract classes ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    j->makeSound();
    i->makeSound();
    delete j;
    delete i;

    // Pure virtual function is not overridden in WrongCat 
    // WrongCat stays abstract - this would NOT compile
    // WrongCat wi;
    
    return 0;
}
