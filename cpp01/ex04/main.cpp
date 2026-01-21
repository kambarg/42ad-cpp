/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:30:00 by gkambarb          #+#    #+#             */
/*   Updated: 2026/01/21 09:28:42 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"
#include <iostream>
#include <fstream>
#include <string>

void runTest(const std::string& testName, 
             const std::string& content,
             const std::string& s1, 
             const std::string& s2)
{
    std::cout << "\n=== " << testName << " ===" << std::endl;
    
    std::string filename = "test_input";
    std::ofstream out(filename.c_str());
    if (!out.is_open())
    {
        std::cerr << "Error: Could not create test file" << std::endl;
        return;
    }
    out << content;
    out.close();
    
    FileReplacer replacer(filename, s1, s2);
    if (replacer.execute())
    {
        std::ifstream result((filename + ".replace").c_str());
        if (result.is_open())
        {
            std::cout << "Input:  \"" << content << "\"" << std::endl;
            std::cout << "s1=\"" << s1 << "\" s2=\"" << s2 << "\"" << std::endl;
            std::cout << "Output: \"";
            char c;
            while (result.get(c))
                std::cout << c;
            std::cout << "\"" << std::endl;
            result.close();
        }
    }
}

void runAllTests()
{
    std::cout << "========================================" << std::endl;
    std::cout << "   Running Automated Test Suite" << std::endl;
    std::cout << "========================================" << std::endl;
    
    runTest("Test 1: Multiple occurrences",
            "Hello world\nHello again\nHello!",
            "Hello", "Hi");
    
    runTest("Test 2: Empty s2 (deletion)",
            "Remove XXX this XXX marks",
            "XXX ", "");
    
    runTest("Test 3: Pattern not found",
            "Nothing to replace here",
            "pattern", "replacement");
    
    runTest("Test 4: s2 longer than s1",
            "hi there hi",
            "hi", "hello");
    
    runTest("Test 5: Empty file",
            "",
            "test", "demo");
    
    runTest("Test 6: Single character replacement",
            "a b A c a",
            "a", "X");
    
    runTest("Test 7: s1 equals s2",
            "same same same",
            "same", "same");
    
    runTest("Test 8: Pattern at start and end",
            "test middle test",
            "test", "REPLACED");
    
    runTest("Test 9: Overlapping pattern",
            "aaaa",
            "aa", "b");
    
    runTest("Test 10: Special characters",
            "Price: $100. Cost: $50.",
            "$", "USD ");
    
    runTest("Test 11: Newlines in content",
            "line1\nline2\nline3",
            "line", "LINE");
    
    runTest("Test 12: Large replacement",
            "x",
            "x", "This is a much longer replacement string");
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "   All Tests Completed!" << std::endl;
    std::cout << "========================================" << std::endl;
}

int main(int argc, char **argv)
{
    if (argc == 2 && std::string(argv[1]) == "--test")
    {
        runAllTests();
        return 0;
    }
    
    if (argc != 4)
    {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        std::cerr << "       " << argv[0] << " --test (run automated tests)" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be empty" << std::endl;
        return 1;
    }

    FileReplacer replacer(filename, s1, s2);

    if (!replacer.execute())
        return 1;

    return 0;
}
