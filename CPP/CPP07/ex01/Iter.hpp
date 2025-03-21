/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:11:08 by hehuang           #+#    #+#             */
/*   Updated: 2025/03/21 22:53:34 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iostream>

template <typename T>
void iter(T* array, size_t size, void(*f)(const T&))
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

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; };

class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};
std::ostream &operator<<( std::ostream & o, Awesome const & rhs )
{ o << rhs.get(); return o; }
