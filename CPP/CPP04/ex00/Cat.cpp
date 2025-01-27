/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:34:45 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/25 15:34:23 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
	this->type_ = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(Cat const &copy) : Animal(copy.type_)
{
		std::cout << "Cat constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &copy)
{
	std::cout << "Cat Assignement called" << std::endl;

	if (this != &copy)
	{
		this->type_ = copy.getType();
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "test sound cat" << std::endl;
}
