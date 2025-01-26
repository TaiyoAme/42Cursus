/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:24:15 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/15 16:56:49 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(){};
Harl::~Harl(){};

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n" << DEBUG_MSG << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]\n" << INFO_MSG << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]\n"<<WARNING_MSG << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]\n" <<ERROR_MSG << std::endl;
}

void Harl::complain(int level)
{
	switch(level)
	{
		case 1:
			debug();
			level++;
		case 2:
			info();
			level++;
		case 3:
			warning();
			level++;
		case 4:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
