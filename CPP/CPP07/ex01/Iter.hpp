/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:11:08 by hehuang           #+#    #+#             */
/*   Updated: 2025/01/25 18:43:11 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iostream>

template <typename T>
void iter(T* array, size_t size, void(*f)(T&))
{
	if (size == 0 || f == NULL)
		return ;
	for (int i = 0; i < size; i++)
		f(array[i]);
}

template <typename T>
void displayElement(T& a)
{
	std::cout << a << std::endl;
}
