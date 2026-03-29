/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 00:34:52 by gkambarb          #+#    #+#             */
/*   Updated: 2026/03/29 17:29:03 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // Animal is now abstract — this would NOT compile:
    // const Animal* meta = new Animal();

    // Cat and Dog are concrete classes, so we can create objects of them
    std::cout << "=== Concrete classes ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl << "=== Sounds ===" << std::endl;
    j->makeSound();
    i->makeSound();

    std::cout << std::endl << "=== Destruction ===" << std::endl;
    delete j;
    delete i;

    return 0;
}
