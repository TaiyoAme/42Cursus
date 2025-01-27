/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:17:32 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/25 16:22:22 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>
#include <string>

AMateria::AMateria() : type_("no_type")
{
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria deconstructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type_(type)
{
	std::cout << "AMateria(type) constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &copy)
{
	if (this != &copy)
	{
		this->type_ = copy.getType();
	}
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (this->type_);
}

