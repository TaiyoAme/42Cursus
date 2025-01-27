/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:19:30 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/25 16:26:52 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <cstddef>
#include <iostream>
#include <string>

Character::Character(): name_("empty")
{
	std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->inventory_[i] = NULL;
	}
	for (int i = 0; i < 10; i++)
	{
		this->floor_[i] = NULL;
	}	
}

Character::Character(std::string name ): name_(name)
{
	std::cout << "Character(name) constructor called" << std::endl;	
	for (int i = 0; i < 4; i++)
	{
		this->inventory_[i] = NULL;
	}
	for (int i = 0; i < 10; i++)
	{
		this->floor_[i] = NULL;
	}	
}


Character::Character(const Character &copy) : name_(copy.getName())
{
    std::cout << "Character COPY constructor is called" << std::endl;
    for (int i = 0; i < 4; i++) {
        this->inventory_[i] = copy.inventory_[i];
    }
    for (int i = 0; i < 10; i++) {
        this->floor_[i] = copy.floor_[i];
    }
}

Character &Character::operator=(const Character &copy)
{
	std::cout << "Character COPY assignement is called" << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++) {
		    this->inventory_[i] = copy.inventory_[i];
		}
		for (int i = 0; i < 10; i++) {
		    this->floor_[i] = copy.floor_[i];
		}
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character deconstructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory_[i] != 0)
			delete this->inventory_[i];
	}
	for (int i = 0; i < 10; i++)
	{
		if (this->floor_[i] != 0)
			delete this->floor_[i];
	}
}

std::string const& Character::getName() const
{
	return this->name_;
}

void	Character::equip(AMateria *m)
{
	for (int i = 0 ; i < 4 ; i++)
	{
		if (this->inventory_[i] == m)
		{
			std::cout << "Already equipped !" << std::endl;
			return;
		}
	}
	for (int i = 0 ; i < 4 ; i++)
	{
		if (this->inventory_[i] == 0)
		{
			std::cout << "Equipped ["<< i <<"/4]!" << std::endl;
			this->inventory_[i] = m;
			return;
		}
	}
	std::cout << "Inventory full !" << std::endl;
}

void	Character::use(int idx, ICharacter &npc)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "wrong index !"<< std::endl;
		return ;
	}
	if (this->inventory_[idx] == 0)
	{
		std::cout << "Index of a empty space !" <<std::endl;
		return ;
	}
	inventory_[idx]->use(npc);
}

void	Character::unequip(int idx)
{
	static int floor_item = 0;
	static int full = 0;
	if (idx < 0 || idx >= 4)
	{
		std::cout << "wrong index !"<< std::endl;
		return ;
	}
	if (this->inventory_[idx] == 0)
	{
		std::cout << "Index of a empty space !" <<std::endl;
		return ;
	}
	if (floor_item >= 10)
	{
		floor_item = 0;
		delete this->floor_[floor_item];
		if (full == 0)
		{
			std::cout << "Floor full starting to delete first Materia dropped" << std::endl;
			full++;
		}
	}
	if (this->floor_[floor_item] != 0)
		delete this->floor_[floor_item];
	this->floor_[floor_item] = this->inventory_[idx];
	this->inventory_[idx] = 0;
	floor_item++;
}
