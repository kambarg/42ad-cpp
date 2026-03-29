/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 00:34:52 by gkambarb          #+#    #+#             */
/*   Updated: 2026/03/29 16:56:42 by gkambarb         ###   ########.fr       */
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

    std::cout << std::endl << "=== Deep copy: Dog (copy constructor) ===" << std::endl;
    std::cout << "Dog/Cat must allocate a new Brain on copy — not share the pointer." << std::endl;
    Dog dog1;
    dog1.getBrain()->ideas[0] = "chase the cat";
    dog1.getBrain()->ideas[1] = "eat food";

    Dog dog2(dog1);
    std::cout << "dog1.brain address: " << dog1.getBrain() << std::endl;
    std::cout << "dog2.brain address: " << dog2.getBrain() << std::endl;
    std::cout << "(Different addresses => each Dog owns its own Brain.)" << std::endl;
    std::cout << "dog1 idea[0]: " << dog1.getBrain()->ideas[0] << std::endl;
    std::cout << "dog2 idea[0]: " << dog2.getBrain()->ideas[0] << std::endl;

    dog2.getBrain()->ideas[0] = "sleep all day";
    std::cout << "After modifying dog2 only:" << std::endl;
    std::cout << "dog1 idea[0]: " << dog1.getBrain()->ideas[0] << std::endl;
    std::cout << "dog2 idea[0]: " << dog2.getBrain()->ideas[0] << std::endl;
    std::cout << "(dog1 unchanged => deep copy of Brain content, not shared.)" << std::endl;

    std::cout << std::endl << "=== Deep copy: Cat (copy assignment) ===" << std::endl;
    Cat cat1;
    cat1.getBrain()->ideas[0] = "knock things off tables";

    Cat cat2;
    cat2 = cat1;
    std::cout << "cat1.brain address: " << cat1.getBrain() << std::endl;
    std::cout << "cat2.brain address: " << cat2.getBrain() << std::endl;
    std::cout << "(Different addresses => assignment also deep-copies Brain.)" << std::endl;
    std::cout << "cat1 idea[0]: " << cat1.getBrain()->ideas[0] << std::endl;
    std::cout << "cat2 idea[0]: " << cat2.getBrain()->ideas[0] << std::endl;

    cat2.getBrain()->ideas[0] = "ignore everyone";
    std::cout << "After modifying cat2 only:" << std::endl;
    std::cout << "cat1 idea[0]: " << cat1.getBrain()->ideas[0] << std::endl;
    std::cout << "cat2 idea[0]: " << cat2.getBrain()->ideas[0] << std::endl;
    std::cout << "(cat1 unchanged => deep copy.)" << std::endl;

    std::cout << std::endl << "=== Shallow copy contrast: WrongCat ===" << std::endl;
    std::cout << "WrongCat copies the Brain* only — both objects share one Brain." << std::endl;
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

    wcat2.brain = NULL; // avoid double-delete: both pointed at the same Brain

    std::cout << std::endl << "=== Destruction ===" << std::endl;
    return 0;
}
