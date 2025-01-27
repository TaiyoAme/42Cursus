/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:49:16 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/25 16:30:16 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"
#include <iostream>

Cure::Cure():AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
};
Cure::~Cure(){
	std::cout << "Cure deconstructor called" << std::endl;
};

Cure::Cure(const Cure &copy) : AMateria(copy.getType())
{
	std::cout << "Cure(type) constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &copy)
{
	if (this != &copy)
	{
		this->type_ = copy.getType();
	}
	return (*this);
}

AMateria *Cure::clone(void) const
{
	return (new Cure());
}

void	Cure::use(ICharacter& npc)
{
	std::cout << "* heals " << npc.getName() << "'s wounds *" << std::endl;
}

