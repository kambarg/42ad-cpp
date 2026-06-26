/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 17:21:27 by ialashqa          #+#    #+#             */
/*   Updated: 2026/02/15 17:21:27 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>

/* ---------------------------------------------- */
/*       Orthodox Canonical Form (private)        */
/* ---------------------------------------------- */

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

/* ---------------------------------------------- */
/*              Detection (private)               */
/* ---------------------------------------------- */

bool ScalarConverter::isPseudoLiteral(const std::string& str)
{
    return (str == "nan" || str == "nanf" ||
            str == "+inf" || str == "-inf" ||
            str == "+inff" || str == "-inff" ||
            str == "inf" || str == "inff");
}

bool ScalarConverter::isChar(const std::string& str)
{
    return (str.length() == 1 && !std::isdigit(str[0]));
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
        if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& str)
{
    size_t len = str.length();
    bool   hasDecimal = false;
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
        else if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    return hasDecimal;
}

bool ScalarConverter::isDouble(const std::string& str)
{
    bool   hasDecimal = false;
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
        else if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    return hasDecimal;
}

/* ---------------------------------------------- */
/*                   Printing                     */
/* ---------------------------------------------- */

void ScalarConverter::printChar(double value, bool impossible)
{
    std::cout << "char: ";
    if (impossible || value != value || value < 0 || value > 127)
        std::cout << "impossible\n";
    else if (value < 32 || value == 127)
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(static_cast<int>(value)) << "'\n";
}

void ScalarConverter::printInt(double value, bool impossible)
{
    std::cout << "int: ";
    if (impossible || value != value
        || value < static_cast<double>(INT_MIN)
        || value > static_cast<double>(INT_MAX))
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(value) << "\n";
}

void ScalarConverter::printFloat(double value, bool impossible)
{
    std::cout << "float: ";
    if (impossible)
    {
        std::cout << "impossible\n";
        return;
    }
    float f = static_cast<float>(value);
    std::cout << f;
    if (f == f && std::fmod(static_cast<double>(f), 1.0) == 0.0)
        std::cout << ".0";
    std::cout << "f\n";
}

void ScalarConverter::printDouble(double value, bool impossible)
{
    std::cout << "double: ";
    if (impossible)
    {
        std::cout << "impossible\n";
        return;
    }
    std::cout << value;
    if (value == value && std::fmod(value, 1.0) == 0.0)
        std::cout << ".0";
    std::cout << "\n";
}

/* ---------------------------------------------- */
/*             Pseudo-literal handler             */
/* ---------------------------------------------- */

void ScalarConverter::handlePseudo(const std::string& str)
{
    double value;

    if (str == "nanf" || str == "nan")
        value = std::numeric_limits<double>::quiet_NaN();
    else if (str == "+inff" || str == "+inf" || str == "inff" || str == "inf")
        value = std::numeric_limits<double>::infinity();
    else
        value = -std::numeric_limits<double>::infinity();

    printChar(value, true);
    printInt(value, true);
    printFloat(value, false);
    printDouble(value, false);
}

/* ---------------------------------------------- */
/*                Public interface                */
/* ---------------------------------------------- */

void ScalarConverter::convert(const std::string& literal)
{
    if (isPseudoLiteral(literal))
    {
        handlePseudo(literal);
        return;
    }

    double value;
    bool   impossible = false;

    if (isChar(literal))
        value = static_cast<double>(literal[0]);
    else if (isInt(literal))
    {
        long l = std::strtol(literal.c_str(), NULL, 10);
        if (l < INT_MIN || l > INT_MAX)
            impossible = true;
        value = static_cast<double>(l);
    }
    else if (isFloat(literal))
        value = static_cast<double>(std::strtod(literal.c_str(), NULL));
    else if (isDouble(literal))
        value = std::strtod(literal.c_str(), NULL);
    else
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    printChar(value, impossible);
    printInt(value, impossible);
    printFloat(value, impossible);
    printDouble(value, impossible);
}
