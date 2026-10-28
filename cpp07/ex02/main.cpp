/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 21:57:00 by gkambarb          #+#    #+#             */
/*   Updated: 2026/10/28 12:26:51 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

int main(void)
{
    std::cout << "=== Empty array ===" << std::endl;
    Array<int> empty;
    
    std::cout << "empty size: " << empty.size() << std::endl;
    try
    {
        std::cout << empty[0] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "empty[0]: " << e.what() << std::endl;
    }
    
    
    std::cout << std::endl;
    std::cout << "=== Array with default ints ===" << std::endl;
    Array<int> numbers(5);
    
    std::cout << "array size: " << numbers.size() << std::endl;
    for (unsigned int i = 0; i < numbers.size(); ++i)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    
    std::cout << std::endl;
    std::cout << "=== Subscript operator [ ] ===" << std::endl;
    for (unsigned int i = 0; i < numbers.size(); ++i)
        numbers[i] = static_cast<int>(i + 1);
    
    for (unsigned int i = 0; i < numbers.size(); ++i)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    std::cout << "out of bounds:" << std::endl;
    try
    {
        std::cout << numbers[numbers.size()] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "numbers[size]: " << e.what() << std::endl;
    }
    
    
    std::cout << std::endl;
    std::cout << "=== Copy constructor ===" << std::endl;
    Array<int> copy(numbers);
    const Array<int> constant(numbers);
    
    copy[0] = 42;
    std::cout << "original[0]: " << numbers[0] << std::endl;
    std::cout << "copy[0]: " << copy[0] << std::endl;    
    std::cout << "constant[0]: " << constant[0] << std::endl;

    
    std::cout << std::endl;
    std::cout << "=== Copy assignment operator ===" << std::endl;
    Array<int> assigned;
    
    assigned = numbers;
    assigned[1] = 99;
    std::cout << "original[1]: " << numbers[1] << std::endl;
    std::cout << "assigned[1]: " << assigned[1] << std::endl;

    std::cout << "self-assignment:" << std::endl;
    assigned = assigned;
    std::cout << "self-assign size: " << assigned.size() << std::endl;

    
    std::cout << std::endl;
    std::cout << "=== Array with strings ===" << std::endl;
    Array<std::string> words(2);

    words[0] = "hello";
    words[1] = "world";
    std::cout << words[0] << std::endl;
    std::cout << words[1] << std::endl;
    return 0;
}
