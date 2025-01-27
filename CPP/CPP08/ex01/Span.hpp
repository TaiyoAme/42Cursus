/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:52:46 by hehuang           #+#    #+#             */
/*   Updated: 2025/01/27 18:25:52 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <list>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <vector>

class Span : public std::list<int>{
public:
	Span();
	Span(unsigned int N);
	Span(const Span &);
	Span &operator=(const Span &);
	~Span();

	void addNumber(int n);
	unsigned int shortestSpan();
	unsigned int longestSpan();

	void	addRange(unsigned int n);

	class LimitReachedException : public std::exception {
	public:
		const char * what() const noexcept override
		{
			return ("LimitReachedException");
		}
	};
	class NotEnoughElementException : public std::exception {
	public:
		const char * what() const noexcept override
		{
			return ("NotEnoughElementException");
		}
	};

private:
	unsigned int size_;
};
