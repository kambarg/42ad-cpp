/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 19:17:40 by ismailalash       #+#    #+#             */
/*   Updated: 2026/03/26 17:43:21 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
    int random = std::rand() % 3;

    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base *p)
{
    if (p && dynamic_cast<A *>(p))
        std::cout << "A\n";
    else if (p && dynamic_cast<B *>(p))
        std::cout << "B\n";
    else if (p && dynamic_cast<C *>(p))
        std::cout << "C\n";
    else
        std::cout << "Unknown type\n";
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A\n";
        return;
    }
    catch (std::exception &e) {}
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B\n";
        return;
    }
    catch (std::exception &e) {}
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C\n";
        return;
    }
    catch (std::exception &e) {}
    std::cout << "Unknown type\n";
}