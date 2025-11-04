/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:55:36 by gkambarb          #+#    #+#             */
/*   Updated: 2025/11/04 09:54:33 by gkambarb         ###   ########.fr       */
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

static std::string truncateString(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::searchContact() const
{
    if (contactCount == 0)
    {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }

    // Display header
    std::cout << std::setw(10) << std::right << "Index" << "|";
    std::cout << std::setw(10) << std::right << "First Name" << "|";
    std::cout << std::setw(10) << std::right << "Last Name" << "|";
    std::cout << std::setw(10) << std::right << "Nickname" << std::endl;

    // Display all contacts
    for (int i = 0; i < contactCount; i++)
    {
        std::cout << std::setw(10) << std::right << i << "|";
        std::cout << std::setw(10) << std::right << truncateString(contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << std::right << truncateString(contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << std::right << truncateString(contacts[i].getNickname()) << std::endl;
    }

    // Prompt for index
    std::cout << "Enter index to display: ";
    std::string input;
    std::getline(std::cin, input);

    // Validate input
    if (input.empty() || input.length() > 1 || !isdigit(input[0]))
    {
        std::cout << "Invalid index!" << std::endl;
        return;
    }

    int index = input[0] - '0';

    if (index < 0 || index >= contactCount)
    {
        std::cout << "Index out of range!" << std::endl;
        return;
    }

    // Display full contact details
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}