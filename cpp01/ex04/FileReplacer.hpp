/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:30:00 by gkambarb          #+#    #+#             */
/*   Updated: 2026/01/20 13:28:58 by gkambarb         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FILEREPLACER_HPP
#define FILEREPLACER_HPP

#include <string>

class FileReplacer
{
    private:
        std::string filename;
        std::string s1;
        std::string s2;

        std::string readFile();
        bool writeFile(const std::string& content);
        std::string replaceAll(const std::string& content);

    public:
        FileReplacer(const std::string& file, const std::string& search,
                     const std::string& replace);
        ~FileReplacer();

        bool execute();
};

#endif
