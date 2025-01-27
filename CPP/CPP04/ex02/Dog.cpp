/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:26:04 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/25 16:08:12 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog(): brain(new Brain)
{
	this->type_ = "Dog";
	std::cout << "Dog constructor called" << std::endl;
};

Dog::Dog(Dog const &copy) : Animal(copy.type_), brain(new Brain(*copy.brain))
{
		std::cout << "Dog constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &copy)
{
	std::cout << "Dog Assignement called" << std::endl;

	if (this != &copy)
	{
		this->type_ = copy.getType();
		this->brain = new Brain(*copy.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

void	Dog::makeSound() const
{
	std::cout << "test sound dog" << std::endl;
}
