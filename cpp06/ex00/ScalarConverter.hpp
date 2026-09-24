/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 10:39:34 by gkambarb          #+#    #+#             */
/*   Updated: 2026/09/24 14:00:00 by gkambarb         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <limits>
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
        static bool isChar(const std::string& str);
        static bool isInt(const std::string& str);
        static bool isFloat(const std::string& str);
        static bool isDouble(const std::string& str);
        static bool isDecimal(const std::string& str);
        static bool hasNonZeroMantissa(const std::string& str);

        // Conversion from the detected type
        static void fromChar(const std::string& str);
        static void fromInt(const std::string& str);
        static void fromFloat(const std::string& str);
        static void fromDouble(const std::string& str);

        // Printing
        static bool isWholeNumber(double value);
        static void printChar(char c, bool possible);
        static void printInt(int i, bool possible);
        static void printFloat(float f, bool possible);
        static void printDouble(double d, bool possible,
                                int precision = std::numeric_limits<double>::digits10);
        static void printImpossible();

    public:
        static void convert(const std::string& literal);
};

#endif
