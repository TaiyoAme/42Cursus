/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:49:16 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/25 16:30:52 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include <iostream>

Ice::Ice():AMateria("ice")
{
	std::cout << "Ice constructor called" << std::endl;
};
Ice::~Ice(){
	std::cout << "Ice deconstructor called" << std::endl;
};

Ice::Ice(const Ice &copy) : AMateria(copy.getType())
{
	std::cout << "Cure(type) constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &copy)
{
	if (this != &copy)
	{
		this->type_ = copy.getType();
	}
	return (*this);
}


AMateria *Ice::clone(void) const
{
	return (new Ice());
}

void	Ice::use(ICharacter& npc)
{
	std::cout << "* shoots an ice bolt at "  << npc.getName() << " *" << std::endl;
}
