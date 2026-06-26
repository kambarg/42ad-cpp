/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 10:48:53 by gkambarb          #+#    #+#             */
/*   Updated: 2026/06/26 10:48:53 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data data;
    data.name = "Gaukhar";
    data.value = 42;

    std::cout << "--- Original Data ---" << std::endl;
    std::cout << "Address:  " << &data << std::endl;
    std::cout << "Name:     " << data.name << std::endl;
    std::cout << "Value:    " << data.value << std::endl;

    std::cout << "\n--- Serialize ---" << std::endl;
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Raw:      " << raw << std::endl;

    std::cout << "\n--- Deserialize ---" << std::endl;
    Data *ptr = Serializer::deserialize(raw);
    std::cout << "Address:  " << ptr << std::endl;
    std::cout << "Name:     " << ptr->name << std::endl;
    std::cout << "Value:    " << ptr->value << std::endl;

    std::cout << "\n=== Comparison ===" << std::endl;
    if (ptr == &data)
        std::cout << "Pointers match!" << std::endl;
    else
        std::cout << "Pointers don't match!" << std::endl;

    return 0;
}