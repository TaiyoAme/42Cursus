/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:52:35 by hehuang           #+#    #+#             */
/*   Updated: 2025/01/27 18:34:55 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <limits>
#include <random>

Span::Span(): size_(0)
{
	std::cout << "Span DEFAULT constructor called" << std::endl;
}

Span::Span(unsigned int n):size_(n)
{
	std::cout << "Span(args) constructor called" << std::endl;
}

Span::Span(const Span &copy):size_(copy.size_)
{
	std::cout << "Span COPY constructor called" << std::endl;
	this->size_ = copy.size_;
	for (const int& val : copy)
	{
		this->push_back(val);
	}
}

Span &Span::operator=(const Span &copy)
{
	std::cout << "Span COPY assignment called" << std::endl;
	if (this != &copy)
	{
		this->size_ = copy.size_;
		for (const int& val : copy)
		{
			this->push_back(val);
		}
	}
	return (*this);
}

Span::~Span()
{
	std::cout << "Span deconstructor called" << std::endl;
}

void Span::addNumber(int n)
{
	if (this->size_ == this->size())
		throw LimitReachedException();
	this->push_back(n);
}

unsigned int Span::shortestSpan()
{
	if (this->size() <= 1)
		throw NotEnoughElementException();

	std::vector<int> sortedList(this->begin(), this->end());
	std::sort(sortedList.begin(), sortedList.end());
	unsigned int minSpan = std::numeric_limits<unsigned int>::max();
	unsigned int sortedSize = sortedList.size();
	for (unsigned int i = 0; i < sortedSize - 1; i++)
	{
		minSpan = std::min(minSpan, static_cast<unsigned int>(sortedList[i + 1] - sortedList[i]));
	}
	return (minSpan);
}

unsigned int Span::longestSpan()
{
	if (this->size() <= 1)
		throw NotEnoughElementException();

	std::vector<int> sortedList(this->begin(), this->end());
	std::sort(sortedList.begin(), sortedList.end());
	unsigned int minSpan = 0;
	unsigned int sortedSize = sortedList.size();
	for (unsigned int i = 0; i < sortedSize - 1; i++)
	{
		minSpan = std::max(minSpan, static_cast<unsigned int>(sortedList[i + 1] - sortedList[i]));
	}
	return (minSpan);
}

void	Span::addRange(unsigned int n)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(std::numeric_limits<int>::min(),std::numeric_limits<int>::max());
	
	for (unsigned int i = 0 ; i < n; i++)
	{
		this->addNumber(dis(gen));
	}
}
