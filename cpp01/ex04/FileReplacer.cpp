/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:30:00 by gkambarb          #+#    #+#             */
/*   Updated: 2026/01/23 12:21:45 by gkambarb         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "FileReplacer.hpp"
#include <fstream>
#include <iostream>

// Constructor
FileReplacer::FileReplacer(const std::string& file, const std::string& search,
                           const std::string& replace)
    : filename(file)
    , s1(search)
    , s2(replace)
{}

// Destructor
FileReplacer::~FileReplacer()
{}

// Execute the replacement operation
bool FileReplacer::execute()
{
    // Read input file
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open file '" << filename << "'" << std::endl;
        return false;
    }

    std::string content;
    char c;
    while (inputFile.get(c))
        content += c;
    inputFile.close();

    // Replace all occurrences of s1 with s2
    std::string result;
    if (!s1.empty())
    {
        size_t pos = 0;
        size_t lastPos = 0;

        while ((pos = content.find(s1, lastPos)) != std::string::npos)
        {
            result.append(content, lastPos, pos - lastPos);
            result.append(s2);
            lastPos = pos + s1.length();
        }
        result.append(content, lastPos, content.length() - lastPos);
    }
    else
        result = content;

    // Write to output file
    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());

    if (!outputFile.is_open())
    {
        std::cerr << "Error: Could not create file '" << outputFilename << "'"
                  << std::endl;
        return false;
    }

    outputFile << result;
    outputFile.close();

    std::cout << "File processed successfully: " << outputFilename << std::endl;
    return true;
}
