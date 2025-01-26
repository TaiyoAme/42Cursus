/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:56:09 by hehuang           #+#    #+#             */
/*   Updated: 2024/11/18 22:10:47 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->oldest_id = -1;
	this->size = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << "See ya" << std::endl;
}

static bool	is_number(std::string str)
{
	if (str.size() > 0)
	{
		int i = 0;
		while (i < str.size())
		{
			if (!isdigit(str[i]))
				return (false);
			i++;
		}
		return (true);
	}
	return (false);
}

static bool	check_nb(std::string str)
{
	if (!std::cin.eof() && !is_number(str))
	{
		std::cout << "Phone number not valid" << std::endl;
		return (false);
	}
	return (true);
}

static std::string get_input (std::string str)
{
	std::string res;
	res = "";
	if (std::cin.eof())
		return res;
	do
	{
		std::cout << str;
		std::getline(std::cin, res);
	}
	while(res.empty() && !std::cin.eof());
	return (res);
}

void	PhoneBook::add_contact()
{
	std::string phone_number;
	this->oldest_id = (this->oldest_id + 1) % 8;
	this->contacts[oldest_id].set_firstname(get_input("Enter first name    : "));
	this->contacts[oldest_id].set_lastname(get_input("Enter last name     : "));
	this->contacts[oldest_id].set_nickname(get_input("Enter nickname	    : "));
	if (!std::cin.eof())
	{
		do
		{
			std::cout << "Enter phone number  : ";
			std::getline(std::cin, phone_number);
		}
		while (!check_nb(phone_number) && !std::cin.eof());
	}
	this->contacts[oldest_id].set_phone_number(phone_number);
	this->contacts[oldest_id].set_dark_secret(get_input("Enter dark secret   : "));
	if (!std::cin.eof())
	{
		if (this->size < 8)
			this->size ++;
		std::cout << "["<<std::to_string(this->oldest_id + 1) << "/"<< std::to_string(this->size) << "]" <<std::endl;
	}
}

static std::string	fix_contact(std::string	str)
{
	std::string	res = "          |";
	int			i = 0;

	while (i < str.size() && i < 9)
	{
		res[i] = str[i];
		i++;
	}
	if (str.size() > 10)
		res[i] = '.';
	else if (str.size() == 10)
		res[i] = str[i];
	return res;
}

void	PhoneBook::search_contact()
{
	int i = 0;
	std::string	str;

	if (this->size == 0) {
        std::cout << "No contacts available in the PhoneBook!" << std::endl;
        return;
    }
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|Index     |First Name|Last Name |Nickname  |" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	while (i <  this->size)
	{
			std::cout	<< "|" << fix_contact(std::to_string(i + 1))
						<< fix_contact(this->contacts[i].get_firstname())
						<< fix_contact(this->contacts[i].get_lastname())
						<< fix_contact(this->contacts[i].get_nickname()) << std::endl;
		i++;
	}
	std::cout << " ------------------------------------------- " << std::endl;
	std::cout << "Select an index : ";
	std::getline(std::cin, str);
	while (!std::cin.eof() && (!is_number(str) || std::stoll(str) > 8 || this->size < std::stoi(str) || std::stoi(str) <= 0))
	{
		std::cout << "Wrong index try again : ";
		std::getline(std::cin, str);
	}
	if (std::cin.eof())
		return;
	this->contacts[std::stoi(str) - 1].display_info();
}
