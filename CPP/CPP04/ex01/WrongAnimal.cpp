/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:30:19 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/25 15:36:39 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(std::string type): type_(type)
{
	std::cout<< "WrongAnimal(type) constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy) : type_(copy.type_)
{
		std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &copy)
{
	std::cout << "WrongAnimal assignement called" << std::endl;
	if (this != &copy)
	{
		this->type_ = copy.getType();
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound () const
{
	std::cout << "test sound WrongAnimal" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type_;
}
