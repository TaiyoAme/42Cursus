/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:12:29 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/23 19:33:52 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <cstddef>
#include <iostream>
#include <string>

ClapTrap::ClapTrap():name_("No_name")
{
	std::cout << "ClapTrap Constructor called" << std::endl;
};

ClapTrap::ClapTrap(std::string name):name_(name)
{
	std::cout << "ClapTrap Constructor(name) called" << std::endl;
};

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "ClapTrap Copy assignement operator called" << std::endl;
	if (this != &copy)
	{
		this->name_ = copy.name_;
	}
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap Destructor called" << std::endl;
};

void	ClapTrap::attack(const std::string &target)
{
	if (this->energy_point_ > 0 && hit_point_ > 0)
	{
		std::cout	<< "ClapTrap " << this->name_ << " attacks "
					<< target << " , causing " << this->attack_damage_ 
					<<" points of damage!" << std::endl;
		this->energy_point_--;
		return;
	}
	if (this->energy_point_ == 0)
		std::cout	<< "ClapTrap " << this->name_ << " has no energy left" 
					<< ", attack failed!"<< std::endl;
	else
		std::cout	<< "ClapTrap " << this->hit_point_<<" has no hp left" 
					<< ", attack failed!"<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_point_ == 0)
	{
		std::cout << "Claptrap " << this->name_ << " health's already empty, it can't take more damge!" << std::endl;
		return;
	}
	else if (this->hit_point_ <= amount)
	{
		std::cout	<< "ClapTrap " << this->name_ << " loss "
					<< this->hit_point_ << " health point, 0hp left!" << std::endl;
		this->hit_point_ = 0;
	}
	else
	{
		this->hit_point_ -= amount;
		std::cout	<< "ClapTrap " << this->name_ << " loss "
					<< amount << " health point, "<< this->hit_point_ <<"hp left!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_point_ < 0)
	{
		std::cout	<< "ClapTrap " << this->name_ << " has no energy left" 
				<< ", reparation failed!"<< std::endl;
		return ;
	}
	else if (this->hit_point_ + amount > this->max_hit_)
	{
		std::cout	<< "ClapTrap "<< this->name_ << " repair itself and restore "
				<< this->max_hit_ - this->hit_point_ << " health point(max)!" << std::endl;
		this->hit_point_ = this->max_hit_;
	}
	else
	{
		std::cout	<< "ClapTrap " << this->name_ << " repair itself and restore "
				<< amount << " health point!" << std::endl;
		this->hit_point_ += amount;
	}
	this->energy_point_--;
}
std::string	ClapTrap::getName()
{
	return this->name_;
}
