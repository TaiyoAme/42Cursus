/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:34:45 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/25 16:05:48 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat"), brain(new Brain)
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(Cat const &copy) : Animal(copy.type_), brain(new Brain(*copy.brain))
{
		std::cout << "Cat constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &copy)
{
	std::cout << "Cat Assignement called" << std::endl;

	if (this != &copy)
	{
		this->type_ = copy.getType();
		this->brain = new Brain(*copy.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "test sound cat" << std::endl;
}
