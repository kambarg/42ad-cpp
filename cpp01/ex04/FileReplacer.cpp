/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:30:00 by gkambarb          #+#    #+#             */
/*   Updated: 2026/01/29 13:40:49 by gkambarb         ###   ########.fr       */
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

// Execute the replacement
bool FileReplacer::execute()
{
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open file '" << filename << "'" << std::endl;
        return false;
    }
    std::string content;
    std::string line;
    while (std::getline(inputFile, line))
    {
        content += line;
        if (!inputFile.eof())
            content += '\n';
    }
    inputFile.close();

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
