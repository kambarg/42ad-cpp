/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:55:46 by gkambarb          #+#    #+#             */
/*   Updated: 2025/10/30 12:07:21 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <string>

class PhoneBook
{
  private:
	static const int MAX_CONTACTS = 8 std::pair<std::string,
		std::string> contacts[MAX_CONTACTS];
	int contactCount;

  public:
	PhoneBook();
	~PhoneBook();
	void addContact(const std::string &name, const std::string &phone);
	void searchContact() const;
};

#endif