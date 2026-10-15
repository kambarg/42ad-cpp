/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 21:57:00 by gkambarb          #+#    #+#             */
/*   Updated: 2026/10/15 16:46:45 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cstddef>
#include <iostream>
#include <string>

template <typename T>
void printElement(const T& value)
{
    std::cout << value << std::endl;
}

template <typename T>
void increment(T& value)
{
    ++value;
}

void appendDot(std::string& value)
{
    value += ".";
}

int main(void)
{
    int numbers[] = {1, 2, 3, 4};
    const unsigned int numbersSize = 4;

    std::cout << "ints:" << std::endl;
    ::iter(numbers, numbersSize, printElement<int>);
    ::iter(numbers, numbersSize, increment<int>);
    std::cout << "ints after increment:" << std::endl;
    ::iter(numbers, numbersSize, printElement<int>);

    const int constants[] = {10, 20, 30};

    std::cout << "const ints:" << std::endl;
    ::iter(constants, 3, printElement<const int>);

    std::string words[] = {"one", "two", "three"};

    std::cout << "strings:" << std::endl;
    ::iter(words, 3, printElement<std::string>);
    ::iter(words, 3, appendDot);
    std::cout << "strings after append:" << std::endl;
    ::iter(words, 3, printElement<std::string>);

    ::iter(numbers, 0, printElement<int>);

    int* empty = NULL;

    ::iter(empty, 5, printElement<int>);
    return 0;
}
