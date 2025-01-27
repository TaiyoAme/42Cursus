/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:51:21 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/25 15:59:15 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"
#include <iostream>
#include <string>

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	for (int i = 0 ; i < 100; i++)
	{
		if (copy.ideas[i].empty())
			break;
		this->ideas[i] = copy.ideas[i];
	}
}


Brain &Brain::operator=(Brain const &copy)
{
	if (this != &copy)
	{
		for (int i = 0 ; i < 100; i++)
		{
			if (copy.ideas[i].empty())
				return (*this);
			this->ideas[i] = copy.ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain deconstructor called" << std::endl;
}
