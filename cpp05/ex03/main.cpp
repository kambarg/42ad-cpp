/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 00:29:17 by gkambarb          #+#    #+#             */
/*   Updated: 2026/05/16 00:29:18 by gkambarb         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << "=== Intern creates forms ===" << std::endl;
	Intern someIntern;

	AForm *form1 = someIntern.makeForm("ShrubberyCreationForm", "garden");
	AForm *form2 = someIntern.makeForm("RobotomyRequestForm", "Bender");
	AForm *form3 = someIntern.makeForm("PresidentialPardonForm", "Arthur Dent");
	AForm *form4 = someIntern.makeForm("invalid form", "target");

	std::cout << "\n=== Valid forms created ===" << std::endl;
	if (form1)
		std::cout << *form1 << std::endl;
	if (form2)
		std::cout << *form2 << std::endl;
	if (form3)
		std::cout << *form3 << std::endl;

	std::cout << "\n=== Bureaucrat signs and executes ===" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		if (form1)
		{
			boss.signForm(*form1);
			boss.executeForm(*form1);
		}
		if (form2)
		{
			boss.signForm(*form2);
			boss.executeForm(*form2);
		}
		if (form3)
		{
			boss.signForm(*form3);
			boss.executeForm(*form3);
		}
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n=== Cleanup ===" << std::endl;
	delete form1;
	delete form2;
	delete form3;
	delete form4;

	return 0;
}
