/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:00:40 by hehuang           #+#    #+#             */
/*   Updated: 2024/11/18 22:11:21 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact() {};
Contact::~Contact() {};

void	Contact::display_info()
{
	std::cout	<< "Firstname     : " << firstname << std::endl
				<< "Lastname      : " << lastname << std::endl
				<< "Nickname      : " << nickname << std::endl
				<< "Phone number  : " << phone_number << std::endl
				<< "Dark secret   : " << dark_secret << std::endl;
}

std::string	Contact::get_firstname()
{
	std::string str;
	str = this->firstname;
	return (str);
}

std::string	Contact::get_lastname()
{
	return (this->lastname);
}

std::string	Contact::get_nickname()
{
	return (this->nickname);
}

void	Contact::set_firstname(const std::string &str)
{
	this->firstname = str;
}

void	Contact::set_lastname(const std::string &str)
{
	this->lastname = str;
}

void	Contact::set_nickname(const std::string &str)
{
	this->nickname = str;
}
void	Contact::set_phone_number(const std::string &str)
{
	this->phone_number = str;
}
void	Contact::set_dark_secret(const std::string &str)
{
	this->dark_secret = str;
}
