/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myTemplates.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:50:38 by hehuang           #+#    #+#             */
/*   Updated: 2025/01/25 18:05:28 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T	min(T& a, T& b)
{
	if (a < b)
		return (a);
	return (b);
}

template<typename T>
T	max(T& a, T& b)
{
	if (a > b)
		return (a);
	return (b);
}
