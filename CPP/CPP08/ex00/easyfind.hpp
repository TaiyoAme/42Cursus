/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:46:39 by hehuang           #+#    #+#             */
/*   Updated: 2025/03/24 17:36:34 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <exception>

class ValueNotFoundException : public std::exception {
public:
	const char * what() const noexcept override
	{
		return ("ValueNotFoundException\n");
	}
};

template <typename T>
typename T::iterator easyfind(T& container, int N) 
{
	typename T::iterator res = std::find(container.begin(), container.end(), N);
	if (res == container.end())
		throw ValueNotFoundException();
	return (res);
}
