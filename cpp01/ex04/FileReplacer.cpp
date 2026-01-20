/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:30:00 by gkambarb          #+#    #+#             */
/*   Updated: 2026/01/20 15:03:09 by gkambarb         ###   ########.fr       */
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

// Read entire file content
std::string FileReplacer::readFile()
{
    std::ifstream inputFile(filename.c_str());

    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open file '" << filename << "'" << std::endl;
        return "";
    }

    std::string content;
    char c;

    while (inputFile.get(c))
        content += c;

    inputFile.close();
    return content;
}

// Write content to output file
bool FileReplacer::writeFile(const std::string& content)
{
    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());

    if (!outputFile.is_open())
    {
        std::cerr << "Error: Could not create file '" << outputFilename << "'"
                  << std::endl;
        return false;
    }

    outputFile << content;
    outputFile.close();

    std::cout << "File processed successfully: " << outputFilename << std::endl;
    return true;
}

// Replace all occurrences of s1 with s2
std::string FileReplacer::replaceAll(const std::string& content)
{
    std::string result;
    size_t pos = 0;
    size_t lastPos = 0;

    if (s1.empty())
        return content;

    while ((pos = content.find(s1, lastPos)) != std::string::npos)
    {
        result.append(content, lastPos, pos - lastPos);
        result.append(s2);
        lastPos = pos + s1.length();
    }
    result.append(content, lastPos, content.length() - lastPos);

    return result;
}

// Execute the replacement operation
bool FileReplacer::execute()
{
    std::string content = readFile();

    if (content.empty() && !filename.empty())
    {
        std::ifstream testFile(filename.c_str());
        if (!testFile.is_open())
            return false;
        testFile.close();
    }

    std::string result = replaceAll(content);
    return writeFile(result);
}
