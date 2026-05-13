/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 03:10:07 by gkambarb          #+#    #+#             */
/*   Updated: 2026/05/14 03:10:09 by gkambarb         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "\n=== Valid construction ===\n";
    try
    {
        Bureaucrat alice("Alice", 42);
        std::cout << alice << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n=== Grade increment and decrement ===\n";
    try
    {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;
        bob.decrementGrade();
        std::cout << bob << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

	std::cout << "\n=== High grade exception ===\n";
    try
    {
        Bureaucrat invalidHigh("TooGood", 0);
        std::cout << invalidHigh << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

	std::cout << "\n=== Low grade exception ===\n";
    try
    {
        Bureaucrat invalidLow("TooBad", 151);
        std::cout << invalidLow << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

	std::cout << "\n=== Boundary checks ===\n";
    try
    {
        Bureaucrat top("Top", 1);
        std::cout << top << std::endl;
        top.incrementGrade();
        std::cout << top << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bottom("Bottom", 150);
        std::cout << bottom << std::endl;
        bottom.decrementGrade();
        std::cout << bottom << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}