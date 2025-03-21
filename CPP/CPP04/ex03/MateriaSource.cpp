/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:29:51 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/25 16:34:54 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <string>

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->spellbook_[i] = NULL;
	}

}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	std::cout << "MateriaSource Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->spellbook_[i] = copy.spellbook_[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
		{
			this->spellbook_[i] = copy.spellbook_[i];
		}
	}
	return (*this);
}


MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource deconstructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->spellbook_[i] != 0)
			delete this->spellbook_[i];
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4 ; i++)
	{
		if (this->spellbook_[i] == 0)
		{
			this->spellbook_[i] = m;
			return ;
		}
	}
	std::cerr << "Spellbook full" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	if (type != "ice" && type != "cure")
	{
		std::cerr << "Type incorrect !" << std::endl;
	}
	for (int i = 0; i < 4; i ++)
	{
		if (this->spellbook_[i]->getType() == type)
		{
			return this->spellbook_[i]->clone();
		}
	}
	std::cerr << "Type not in spellbook !" << std::endl;
	return (NULL);
}
