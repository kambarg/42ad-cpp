/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 00:19:31 by gkambarb          #+#    #+#             */
/*   Updated: 2026/06/29 11:53:46 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include <string>

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern(void);

		AForm *makeForm(const std::string &formName, const std::string &target);

	private:
		AForm *makeShrubberyCreationForm(const std::string &target);
		AForm *makeRobotomyRequestForm(const std::string &target);
		AForm *makePresidentialPardonForm(const std::string &target);
};

#endif
