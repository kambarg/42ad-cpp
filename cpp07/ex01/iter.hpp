/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkambarb <gkambarb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 21:57:00 by gkambarb          #+#    #+#             */
/*   Updated: 2026/10/14 21:57:00 by gkambarb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T, typename F>
void iter(T* array, const unsigned int length, F func)
{
    if (array == NULL)
        return;
    for (unsigned int i = 0; i < length; ++i)
        func(array[i]);
}

#endif
