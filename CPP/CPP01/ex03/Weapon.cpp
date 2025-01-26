/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:26:14 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/13 17:58:59 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>
#include <string>

Weapon::Weapon() {};
Weapon::Weapon(std::string type) : type(type) {};
Weapon::~Weapon() {};

std::string	Weapon::getType()
{
	return this->type;
}

void	Weapon::setType(std::string newType)
{
	this->type = newType;
}
