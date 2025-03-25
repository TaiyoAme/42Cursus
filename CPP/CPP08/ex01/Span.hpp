/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:52:46 by hehuang           #+#    #+#             */
/*   Updated: 2025/03/24 18:59:12 by hehuang          ###   ########.fr       */
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

	template<typename Iterator>
	void	addRange(Iterator begin, Iterator end)
	{
		if (distance(begin, end) + this->size() > this->size_) {
            throw (std::out_of_range("no enough space left"));
        }
        this->insert(this->end(), begin, end);
	}

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
