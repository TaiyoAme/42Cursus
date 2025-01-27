/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:55:50 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/23 19:34:25 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap():ClapTrap("Noname")
{
	std::cout << "ScavTrap Constructor called" << std::endl;
	this->hit_point_ = 100;
	this->energy_point_ = 50;
	this->attack_damage_ = 20;
	this->max_hit_ = 100;
};


ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
	std::cout << "ScavTrap Constructor(name) called" << std::endl;
	this->hit_point_ = 100;
	this->energy_point_ = 50;
	this->attack_damage_ = 20;
	this->max_hit_ = 100;
};

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout << "ScavTrap Copy assignement operator called" << std::endl;
	if (this != &copy)
	{
		this->name_ = copy.name_;
		this->hit_point_ = 100;
		this->energy_point_ = 50;
		this->attack_damage_ = 20;
		this->max_hit_ = 100;
	}
	return (*this);
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap Destructor called" << std::endl;
};

void	ScavTrap::attack(const std::string &target)
{
	if (this->energy_point_ > 0 && this->hit_point_ > 0)
	{
		std::cout	<< "ScavTrap " << this->name_ << " attacks "
					<< target << " , causing " << this->attack_damage_ 
					<<" points of damage!" << std::endl;
		this->energy_point_--;
		return ;
	}
	if (this->energy_point_ == 0)
		std::cout	<< "ScavTrap " << this->name_ << " has no energy left" 
					<< ", attack failed!"<< std::endl;
	else
		std::cout	<< "ScavTrap " << this->name_<< this->hit_point_ << " has no hp left" 
					<< ", attack failed!"<< std::endl;
}

void	ScavTrap::guardGate()
{
	if (!this->guarding)
	{
		this->guarding = true;
		std::cout << "ScavTrap " << this->name_ << " is now in guard mode!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->name_ << " is already in guard mode!" << std::endl;
}
