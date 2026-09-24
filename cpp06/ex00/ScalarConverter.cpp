/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 10:39:54 by gkambarb          #+#    #+#             */
/*   Updated: 2026/09/24 14:00:00 by gkambarb         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.hpp"

#include <cctype>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

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
// A char literal is either quoted ('c') or a single non-digit character (c).
bool ScalarConverter::isChar(const std::string& str)
{
    if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
        return true;
    return (str.length() == 1
            && !std::isdigit(static_cast<unsigned char>(str[0])));
}

bool ScalarConverter::isInt(const std::string& str)
{
    size_t i = 0;

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
    if (str == "nanf" || str == "+inff" || str == "-inff")
        return true;
    if (str.length() < 2 || str[str.length() - 1] != 'f')
        return false;
    return isDecimal(str.substr(0, str.length() - 1));
}

bool ScalarConverter::isDouble(const std::string& str)
{
    if (str == "nan" || str == "+inf" || str == "-inf")
        return true;
    return isDecimal(str);
}

// [sign] digits with at most one '.' [e|E [sign] digits]
// At least one mantissa digit, and a '.' or an exponent (otherwise it's an int).
bool ScalarConverter::isDecimal(const std::string& str)
{
    bool   hasDot = false;
    bool   hasDigit = false;
    bool   hasExponent = false;
    size_t i = 0;

    if (str.empty())
        return false;
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (i < str.length() && str[i] != 'e' && str[i] != 'E')
    {
        if (str[i] == '.')
        {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if (std::isdigit(static_cast<unsigned char>(str[i])))
            hasDigit = true;
        else
            return false;
        i++;
    }
    if (!hasDigit)
        return false;
    if (i < str.length())
    {
        hasExponent = true;
        i++;
        if (i < str.length() && (str[i] == '+' || str[i] == '-'))
            i++;
        if (i == str.length())
            return false;
        while (i < str.length())
        {
            if (!std::isdigit(static_cast<unsigned char>(str[i])))
                return false;
            i++;
        }
    }
    return (hasDot || hasExponent);
}

// A parsed value of zero is an underflow when the mantissa isn't all zeros.
bool ScalarConverter::hasNonZeroMantissa(const std::string& str)
{
    for (size_t i = 0; i < str.length() && str[i] != 'e' && str[i] != 'E'; i++)
    {
        if (str[i] >= '1' && str[i] <= '9')
            return true;
    }
    return false;
}

// Conversion from the detected type
void ScalarConverter::fromChar(const std::string& str)
{
    char c;

    if (str.length() == 3)
        c = str[1];
    else
        c = str[0];

    printChar(c, true);
    printInt(static_cast<int>(c), true);
    printFloat(static_cast<float>(c), true);
    printDouble(static_cast<double>(c), true);
}

void ScalarConverter::fromInt(const std::string& str)
{
    std::istringstream iss(str);
    int                i;

    iss >> i;
    if (iss.fail())
    {
        printImpossible();
        return;
    }

    bool charOk = (i >= 0 && i <= 127);
    char c = 0;

    if (charOk)
        c = static_cast<char>(i);

    printChar(c, charOk);
    printInt(i, true);
    printFloat(static_cast<float>(i), true);
    printDouble(static_cast<double>(i), true);
}

void ScalarConverter::fromFloat(const std::string& str)
{
    float f;

    if (str == "nanf")
        f = std::numeric_limits<float>::quiet_NaN();
    else if (str == "+inff")
        f = std::numeric_limits<float>::infinity();
    else if (str == "-inff")
        f = -std::numeric_limits<float>::infinity();
    else
    {
        // Extraction stops at the trailing 'f'.
        std::istringstream iss(str);

        iss >> f;
        if (iss.fail() || (f == 0.0f && hasNonZeroMantissa(str)))
        {
            printImpossible();
            return;
        }
    }

    // NaN fails every comparison, so it is rejected by these checks.
    // static_cast<float>(INT_MAX) rounds up to 2^31, hence the strict '<'.
    bool charOk = (f >= 0.0f && f <= 127.0f);
    bool intOk = (f >= static_cast<float>(INT_MIN)
                  && f < static_cast<float>(INT_MAX));
    char c = 0;
    int  i = 0;

    if (charOk)
        c = static_cast<char>(f);
    if (intOk)
        i = static_cast<int>(f);

    printChar(c, charOk);
    printInt(i, intOk);
    printFloat(f, true);
    // A float only carries float precision; more digits would show its
    // rounding error (4.2f would print as 4.19999980926514).
    printDouble(static_cast<double>(f), true,
                std::numeric_limits<float>::digits10);
}

void ScalarConverter::fromDouble(const std::string& str)
{
    double d;

    if (str == "nan")
        d = std::numeric_limits<double>::quiet_NaN();
    else if (str == "+inf")
        d = std::numeric_limits<double>::infinity();
    else if (str == "-inf")
        d = -std::numeric_limits<double>::infinity();
    else
    {
        std::istringstream iss(str);

        iss >> d;
        if (iss.fail() || (d == 0.0 && hasNonZeroMantissa(str)))
        {
            printImpossible();
            return;
        }
    }

    bool charOk = (d >= 0.0 && d <= 127.0);
    bool intOk = (d >= static_cast<double>(INT_MIN)
                  && d <= static_cast<double>(INT_MAX));
    bool floatOk = (d != d || std::fabs(d) == std::numeric_limits<double>::infinity()
                    || std::fabs(d) <= std::numeric_limits<float>::max());
    char  c = 0;
    int   i = 0;
    float f = 0.0f;

    if (charOk)
        c = static_cast<char>(d);
    if (intOk)
        i = static_cast<int>(d);
    if (floatOk)
        f = static_cast<float>(d);
    // Too small for a float: the cast underflowed to zero.
    if (floatOk && f == 0.0f && d != 0.0)
        floatOk = false;

    printChar(c, charOk);
    printInt(i, intOk);
    printFloat(f, floatOk);
    printDouble(d, true);
}

// Printing
// Casting NaN, inf or anything beyond the long long range is undefined,
// so only finite values of reasonable magnitude reach the cast.
bool ScalarConverter::isWholeNumber(double value)
{
    if (value != value || std::fabs(value) >= 1e16)
        return false;
    return (value == static_cast<long long>(value));
}

void ScalarConverter::printChar(char c, bool possible)
{
    std::cout << "char: ";
    if (!possible)
        std::cout << "impossible\n";
    else if (!std::isprint(static_cast<unsigned char>(c)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << c << "'\n";
}

void ScalarConverter::printInt(int i, bool possible)
{
    std::cout << "int: ";
    if (!possible)
        std::cout << "impossible\n";
    else
        std::cout << i << "\n";
}

void ScalarConverter::printFloat(float f, bool possible)
{
    std::cout << "float: ";
    if (!possible)
    {
        std::cout << "impossible\n";
        return;
    }
    if (isWholeNumber(static_cast<double>(f)))
        std::cout << std::fixed << std::setprecision(1);
    else
    {
        std::cout.unsetf(std::ios::floatfield);
        std::cout << std::setprecision(std::numeric_limits<float>::digits10);
    }
    std::cout << f << "f\n";
}

void ScalarConverter::printDouble(double d, bool possible, int precision)
{
    std::cout << "double: ";
    if (!possible)
    {
        std::cout << "impossible\n";
        return;
    }
    if (isWholeNumber(d))
        std::cout << std::fixed << std::setprecision(1);
    else
    {
        std::cout.unsetf(std::ios::floatfield);
        std::cout << std::setprecision(precision);
    }
    std::cout << d << "\n";
}

void ScalarConverter::printImpossible()
{
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
}

// Public interface - static method convert
void ScalarConverter::convert(const std::string& literal)
{
    if (literal.empty())
        printImpossible();
    else if (isChar(literal))
        fromChar(literal);
    else if (isInt(literal))
        fromInt(literal);
    else if (isFloat(literal))
        fromFloat(literal);
    else if (isDouble(literal))
        fromDouble(literal);
    else
        printImpossible();
}
