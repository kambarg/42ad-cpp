/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 10:51:45 by gkambarb          #+#    #+#             */
/*   Updated: 2026/06/26 10:51:46 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime> 
#include <iostream>

int main(void)
{
    srand(time(NULL));
    Base *a = new A();
    Base *b = new B();
    Base *c = new C();

    std::cout << "A -> Pointer: ";
    identify(a);
    std::cout << "A -> Reference: ";
    identify(*a);

    std::cout << "B -> Pointer: ";
    identify(b);
    std::cout << "B -> Reference: ";
    identify(*b);

    std::cout << "C -> Pointer: ";
    identify(c);
    std::cout << "C -> Reference: ";
    identify(*c);

    delete a;
    delete b;
    delete c;

    std::cout << "\n=== Random Types Test ===" << std::endl;
    for (int i = 1; i <= 5; i++)
    {
        Base *random = generate();
        std::cout << "Random " << i << " -> Pointer: ";
        identify(random);
        std::cout << "Random " << i << " -> Reference: ";
        identify(*random);
        delete random;
    }
    
    return 0;
}