/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 00:34:52 by gkambarb          #+#    #+#             */
/*   Updated: 2026/03/22 16:54:18 by gkambarb         ###   ########.fr       */
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
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    std::cout << std::endl << "=== Animal array (half Dog, half Cat) ===" << std::endl;
    const int size = 10;
    Animal* animals[size];

    for (int k = 0; k < size / 2; k++)
        animals[k] = new Dog();
    for (int k = size / 2; k < size; k++)
        animals[k] = new Cat();

    std::cout << std::endl << "=== Sounds ===" << std::endl;
    for (int k = 0; k < size; k++)
        animals[k]->makeSound();

    std::cout << std::endl << "=== Deleting array ===" << std::endl;
    for (int k = 0; k < size; k++)
        delete animals[k];

    std::cout << std::endl << "=== Deep copy test (Dog) ===" << std::endl;
    Dog dog1;
    dog1.getBrain()->ideas[0] = "chase the cat";
    dog1.getBrain()->ideas[1] = "eat food";

    Dog dog2(dog1);
    std::cout << "dog1 idea[0]: " << dog1.getBrain()->ideas[0] << std::endl;
    std::cout << "dog2 idea[0]: " << dog2.getBrain()->ideas[0] << std::endl;

    dog2.getBrain()->ideas[0] = "sleep all day";
    std::cout << "After modifying dog2:" << std::endl;
    std::cout << "dog1 idea[0]: " << dog1.getBrain()->ideas[0] << std::endl;
    std::cout << "dog2 idea[0]: " << dog2.getBrain()->ideas[0] << std::endl;

    std::cout << std::endl << "=== Deep copy test (Cat) ===" << std::endl;
    Cat cat1;
    cat1.getBrain()->ideas[0] = "knock things off tables";

    Cat cat2;
    cat2 = cat1;
    std::cout << "cat1 idea[0]: " << cat1.getBrain()->ideas[0] << std::endl;
    std::cout << "cat2 idea[0]: " << cat2.getBrain()->ideas[0] << std::endl;

    cat2.getBrain()->ideas[0] = "ignore everyone";
    std::cout << "After modifying cat2:" << std::endl;
    std::cout << "cat1 idea[0]: " << cat1.getBrain()->ideas[0] << std::endl;
    std::cout << "cat2 idea[0]: " << cat2.getBrain()->ideas[0] << std::endl;

    std::cout << std::endl << "=== Shallow copy test (WrongCat) ===" << std::endl;
    WrongCat wcat1;
    wcat1.brain->ideas[0] = "wrong idea";

    WrongCat wcat2(wcat1);
    std::cout << "wcat1 idea[0]: " << wcat1.brain->ideas[0] << std::endl;
    std::cout << "wcat2 idea[0]: " << wcat2.brain->ideas[0] << std::endl;
    std::cout << "wcat1.brain address: " << wcat1.brain << std::endl;
    std::cout << "wcat2.brain address: " << wcat2.brain << std::endl;

    wcat2.brain->ideas[0] = "modified wrong idea";
    std::cout << "After modifying wcat2:" << std::endl;
    std::cout << "wcat1 idea[0]: " << wcat1.brain->ideas[0] << std::endl;
    std::cout << "wcat2 idea[0]: " << wcat2.brain->ideas[0] << std::endl;
    std::cout << "(Both changed! Shallow copy — same Brain in memory)" << std::endl;

    wcat2.brain = NULL; // to prevent double-delete crash

    std::cout << std::endl << "=== Destruction ===" << std::endl;
    return 0;
}
