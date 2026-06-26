/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 17:19:13 by ialashqa          #+#    #+#             */
/*   Updated: 2026/02/15 17:19:13 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <limits>
#include <cmath>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

        static bool isPseudoLiteral(const std::string& str);
        static bool isChar(const std::string& str);
        static bool isInt(const std::string& str);
        static bool isFloat(const std::string& str);
        static bool isDouble(const std::string& str);

        static void printChar(double value, bool impossible);
        static void printInt(double value, bool impossible);
        static void printFloat(double value, bool impossible);
        static void printDouble(double value, bool impossible);
        static void handlePseudo(const std::string& str);

    public:
        static void convert(const std::string& input);
};

#endif
