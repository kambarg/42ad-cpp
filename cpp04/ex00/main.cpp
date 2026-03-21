/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 12:57:25 by gkambarb          #+#    #+#             */
/*   Updated: 2026/03/21 12:57:27 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Subject test ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;

    std::cout << std::endl << "=== WrongAnimal test ===" << std::endl;
    const WrongAnimal* wmeta = new WrongAnimal();
    const WrongAnimal* wi = new WrongCat();
    std::cout << wi->getType() << std::endl;
    wi->makeSound();
    wmeta->makeSound();
    delete wmeta;
    delete wi;

    std::cout << std::endl << "=== Stack objects test ===" << std::endl;
    Dog dog;
    Cat cat;
    dog.makeSound();
    cat.makeSound();

    std::cout << std::endl << "=== Copy test ===" << std::endl;
    Dog dog2(dog);
    Cat cat2;
    cat2 = cat;
    dog2.makeSound();
    cat2.makeSound();

    std::cout << std::endl << "=== Destruction ===" << std::endl;
    return 0;
}
