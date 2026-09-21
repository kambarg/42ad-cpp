/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 10:39:34 by gkambarb          #+#    #+#             */
/*   Updated: 2026/09/21 15:01:10 by gkambarb         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

// ScalarConverter class cannot be instantiated. 
// It has one public static method convert 
// that is called on the class directly, not on an object
class ScalarConverter
{
    private:
        // Orthodox Canonical Form
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

        // Type detection
        static bool isPseudoLiteral(const std::string& str);
        static bool isChar(const std::string& str);
        static bool isInt(const std::string& str);
        static bool isFloat(const std::string& str);
        static bool isDouble(const std::string& str);

        // Printing
        static void printChar(double value, bool impossible);
        static void printInt(double value, bool impossible);
        static void printFloat(double value, bool impossible);
        static void printDouble(double value, bool impossible);
        static void handlePseudo(const std::string& str);

    public:
        static void convert(const std::string& input);
};

#endif
