/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 04:25:14 by gkambarb          #+#    #+#             */
/*   Updated: 2026/05/14 04:25:16 by gkambarb         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "\n=== Valid bureaucrats and forms ===\n";
	try
	{
		Bureaucrat alice("Alice", 42);
		Form tax("Tax form", 50, 20);
		std::cout << alice << std::endl;
		std::cout << tax << std::endl;
		alice.signForm(tax);
		std::cout << tax << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n=== Signing succeeds ===\n";
	try
	{
		Bureaucrat boss("Boss", 1);
		Form contract("Contract", 1, 1);
		boss.signForm(contract);
		std::cout << contract << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n=== Signing fails because grade is too low ===\n";
	try
	{
		Bureaucrat intern("Intern", 150);
		Form topSecret("Top secret", 10, 10);
		intern.signForm(topSecret);
		std::cout << topSecret << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n=== Invalid form grades ===\n";
	try
	{
		Form badHigh("Bad high", 0, 10);
		std::cout << badHigh << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form badLow("Bad low", 10, 151);
		std::cout << badLow << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
