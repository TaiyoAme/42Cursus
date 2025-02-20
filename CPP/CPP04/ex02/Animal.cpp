/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:30:19 by hehuang           #+#    #+#             */
/*   Updated: 2025/02/20 15:34:52 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
}
Animal::Animal(std::string type): type_(type)
{
	std::cout<< "Animal(type) constructor called" << std::endl;
}
Animal::Animal(Animal const &f) : type_(f.type_)
{
	std::cout<< "Copy constructor called" << std::endl;
}
Animal	&Animal::operator=(Animal const &copy)
{
	std::cout<< "Copy assignement called" << std::endl;

	if (this != &copy)
	{
		this->type_ = copy.getType();
	}
	return (*this);
}
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return this->type_;
}
