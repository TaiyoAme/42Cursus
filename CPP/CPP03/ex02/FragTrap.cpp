/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:18:38 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/23 19:33:27 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap():ClapTrap("NoName")
{
	std::cout << "FragTrap Constructor called" << std::endl;
	this->hit_point_ = 100;
	this->energy_point_ = 100;
	this->attack_damage_ = 30;
	this->max_hit_ = 100;
};

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
	std::cout << "FragTrap Constructor(name) called" << std::endl;
	this->hit_point_ = 100;
	this->energy_point_ = 100;
	this->attack_damage_ = 30;
	this->max_hit_ = 100;
};

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	std::cout << "FragTrap Copy assignement operator called" << std::endl;
	if (this != &copy)
	{
		this->name_ = copy.name_;
		this->hit_point_ = 100;
		this->energy_point_ = 100;
		this->attack_damage_ = 30;
		this->max_hit_ = 100;
	}
	return (*this);
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap Destructor called" << std::endl;
};

void	FragTrap::highFivesGuys(void)
{
	std::cout << "High Five ! ✋" << std::endl;
}
