/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 21:57:00 by gkambarb          #+#    #+#             */
/*   Updated: 2026/10/14 21:57:00 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array(void) : _elements(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _elements(NULL), _size(n)
{
    if (n > 0)
        _elements = new T[n]();
}

template <typename T>
Array<T>::Array(const Array& other) : _elements(NULL), _size(0)
{
    *this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        T* copy = NULL;

        if (other._size > 0)
        {
            copy = new T[other._size]();
            for (unsigned int i = 0; i < other._size; ++i)
                copy[i] = other._elements[i];
        }
        delete [] _elements;
        _elements = copy;
        _size = other._size;
    }
    return *this;
}

template <typename T>
Array<T>::~Array(void)
{
    delete [] _elements;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw Array<T>::OutOfBoundsException();
    return _elements[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw Array<T>::OutOfBoundsException();
    return _elements[index];
}

template <typename T>
unsigned int Array<T>::size(void) const
{
    return _size;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
    return "index out of bounds";
}

#endif
