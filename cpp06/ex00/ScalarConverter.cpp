/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 10:39:54 by gkambarb          #+#    #+#             */
/*   Updated: 2026/09/21 15:06:05 by gkambarb         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.hpp"

#include <cctype>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

// Orthodox Canonical Form
ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}

// Type detection
bool ScalarConverter::isPseudoLiteral(const std::string& str)
{
    return (str == "nan" || str == "nanf" ||
            str == "+inf" || str == "-inf" ||
            str == "+inff" || str == "-inff" ||
            str == "inf" || str == "inff");
}

bool ScalarConverter::isChar(const std::string& str)
{
    return (str.length() == 1
            && !std::isdigit(static_cast<unsigned char>(str[0])));
}

bool ScalarConverter::isInt(const std::string& str)
{
    size_t i = 0;

    if (str.empty())
        return false;
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (i == str.length())
        return false;
    while (i < str.length())
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return false;
        i++;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& str)
{
    size_t len = str.length();
    bool   hasDecimal = false;
    bool   hasDigit = false;
    size_t i = 0;

    if (len < 2 || str[len - 1] != 'f')
        return false;
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (i == len - 1)
        return false;
    while (i < len - 1)
    {
        if (str[i] == '.')
        {
            if (hasDecimal)
                return false;
            hasDecimal = true;
        }
        else if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return false;
        else
            hasDigit = true;
        i++;
    }
    return (hasDecimal && hasDigit);
}

bool ScalarConverter::isDouble(const std::string& str)
{
    bool   hasDecimal = false;
    bool   hasDigit = false;
    size_t i = 0;

    if (str.empty())
        return false;
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (i == str.length())
        return false;
    while (i < str.length())
    {
        if (str[i] == '.')
        {
            if (hasDecimal)
                return false;
            hasDecimal = true;
        }
        else if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return false;
        else
            hasDigit = true;
        i++;
    }
    return (hasDecimal && hasDigit);
}

// Printing output
// Beyond 1e16 a whole value needs more digits than fixed notation can show
// readably, so it is left to scientific notation instead of gaining a ".0".
bool ScalarConverter::isWholeNumber(double value)
{
    return (value == value && std::fabs(value) < 1e16
            && std::fmod(value, 1.0) == 0.0);
}

void ScalarConverter::printChar(double value)
{
    char c;

    std::cout << "char: ";
    if (value != value || value < 0 || value > 127)
        std::cout << "impossible\n";
    else if (value < 32 || value == 127)
        std::cout << "Non displayable\n";
    else
    {
        c = static_cast<char>(static_cast<int>(value));
        std::cout << "'" << c << "'\n";
    }
}

void ScalarConverter::printInt(double value)
{
    std::cout << "int: ";
    if (value != value
        || value < static_cast<double>(INT_MIN)
        || value > static_cast<double>(INT_MAX))
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(value) << "\n";
}

void ScalarConverter::printFloat(double value)
{
    float f = static_cast<float>(value);

    std::cout << "float: ";
    if (isWholeNumber(static_cast<double>(f)))
        std::cout << std::fixed << std::setprecision(1) << f << "f\n";
    else
    {
        std::cout.unsetf(std::ios::floatfield);
        std::cout << std::setprecision(std::numeric_limits<float>::digits10)
                  << f << "f\n";
    }
}

void ScalarConverter::printDouble(double value)
{
    std::cout << "double: ";
    if (isWholeNumber(value))
        std::cout << std::fixed << std::setprecision(1) << value << "\n";
    else
    {
        std::cout.unsetf(std::ios::floatfield);
        std::cout << std::setprecision(std::numeric_limits<double>::digits10)
                  << value << "\n";
    }
}

// Pseudo-literal handler
void ScalarConverter::handlePseudo(const std::string& str)
{
    double value;

    if (str == "nanf" || str == "nan")
        value = std::numeric_limits<double>::quiet_NaN();
    else if (str == "+inff" || str == "+inf" || str == "inff" || str == "inf")
        value = std::numeric_limits<double>::infinity();
    else
        value = -std::numeric_limits<double>::infinity();

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

// Public interface - static method convert
void ScalarConverter::convert(const std::string& literal)
{
    if (isPseudoLiteral(literal))
    {
        handlePseudo(literal);
        return;
    }

    double value;

    if (isChar(literal))
        value = static_cast<double>(static_cast<unsigned char>(literal[0]));
    else if (isInt(literal) || isFloat(literal) || isDouble(literal))
        value = std::strtod(literal.c_str(), NULL);
    else
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}
