/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:55:36 by gkambarb          #+#    #+#             */
/*   Updated: 2025/10/30 15:08:01 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0)
{
    std::cout << "...PhoneBook default constructor called..." << std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << "...PhoneBook destructor called..." << std::endl;
}

void PhoneBook::addContact()
{
    Contact newContact;
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);
    if (firstName.empty()) { std::cout << "Field cannot be empty.\n"; return; }

    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);
    if (lastName.empty()) { std::cout << "Field cannot be empty.\n"; return; }

    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    if (nickname.empty()) { std::cout << "Field cannot be empty.\n"; return; }

    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);
    if (phoneNumber.empty()) { std::cout << "Field cannot be empty.\n"; return; }

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkestSecret);
    if (darkestSecret.empty()) { std::cout << "Field cannot be empty.\n"; return; }

    // Set all fields at once
    newContact.setAllFields(firstName, lastName, nickname, phoneNumber, darkestSecret);

    // Add the new contact to the phonebook
    if (contactCount < MAX_CONTACTS)
    {
        contacts[contactCount] = newContact;
        contactCount++;
    }
    else
    {
        for (int i = 1; i < MAX_CONTACTS; i++)
        {
            contacts[i - 1] = contacts[i];
        }
        contacts[MAX_CONTACTS - 1] = newContact;
    }

    std::cout << "Contact added successfully!" << std::endl;
}