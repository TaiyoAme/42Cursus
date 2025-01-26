/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:24:15 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/15 16:42:12 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(){};
Harl::~Harl(){};

void Harl::debug(void)
{
	std::cout << DEBUG_MSG << std::endl;
}

void Harl::info(void)
{
	std::cout << INFO_MSG << std::endl;
}

void Harl::warning(void)
{
	std::cout << WARNING_MSG << std::endl;
}

void Harl::error(void)
{
	std::cout << ERROR_MSG << std::endl;
}

void Harl::complain(int level)
{
	switch(level)
	{
		case 1:
			debug();
			break;
		case 2:
			info();
			break;
		case 3:
			warning();
			break;
		case 4:
			error();
			break;
		default:
			break;
	}
}
