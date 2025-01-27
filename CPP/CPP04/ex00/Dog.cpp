/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:26:04 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/25 15:34:05 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	this->type_ = "Dog";
	std::cout << "Dog constructor called" << std::endl;
};

Dog::Dog(Dog const &copy) : Animal(copy.type_)
{
		std::cout << "Dog constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &copy)
{
	std::cout << "Dog assignement called" << std::endl;
	if (this != &copy)
	{
		this->type_ = copy.getType();
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "test sound dog" << std::endl;

}
