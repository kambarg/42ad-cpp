/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 00:19:36 by gkambarb          #+#    #+#             */
/*   Updated: 2026/05/16 00:19:37 by gkambarb         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern(void)
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern(void)
{
}

AForm *Intern::makeShrubberyCreationForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	if (formName == "ShrubberyCreationForm")
		return makeShrubberyCreationForm(target);
	if (formName == "RobotomyRequestForm")
		return makeRobotomyRequestForm(target);
	if (formName == "PresidentialPardonForm")
		return makePresidentialPardonForm(target);
	std::cout << "Error: form \"" << formName << "\" not recognized." << std::endl;
	return NULL;
}
