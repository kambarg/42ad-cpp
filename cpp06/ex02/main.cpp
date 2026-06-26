/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 21:58:38 by ismailalash       #+#    #+#             */
/*   Updated: 2026/03/16 23:01:53 by ismailalash      ###   ########.fr       */
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