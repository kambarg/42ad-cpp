/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 21:57:00 by gkambarb          #+#    #+#             */
/*   Updated: 2026/10/28 12:30:36 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <exception>

template <typename T>
class Array
{
    private:
        T*              _elements;
        unsigned int    _size;

    public:
        Array(void);
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array(void);

        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;

        unsigned int size(void) const;

        class OutOfBoundsException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

# include "Array.tpp"

#endif