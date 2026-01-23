/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:30:00 by gkambarb          #+#    #+#             */
/*   Updated: 2026/01/23 12:21:52 by gkambarb         ###   ########.fr       */
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

    public:
        FileReplacer(const std::string& file, const std::string& search,
                     const std::string& replace);
        ~FileReplacer();

        bool execute();
};

#endif
