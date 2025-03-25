/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:05:35 by hehuang           #+#    #+#             */
/*   Updated: 2025/03/25 18:51:10 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack(){};
	MutantStack(const MutantStack &copy){};
	MutantStack &operator=(const MutantStack &copy)
	{
        if (this != &copy)
            std::stack<T>::operator=(copy);
        return *this;
	}
	~MutantStack(){};

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	// Itérateurs normaux
	iterator begin() { return std::stack<T>::c.begin(); }
	iterator end() { return std::stack<T>::c.end(); }

	// Itérateurs constants
	const_iterator begin() const { return std::stack<T>::c.begin(); }
	const_iterator end() const { return std::stack<T>::c.end(); }

	// Itérateurs inversés
	reverse_iterator rbegin() { return std::stack<T>::c.rbegin(); }
	reverse_iterator rend() { return std::stack<T>::c.rend(); }

	// Itérateurs inversés constants
	const_reverse_iterator rbegin() const { return std::stack<T>::c.rbegin(); }
	const_reverse_iterator rend() const { return std::stack<T>::c.rend(); }

private:
};
