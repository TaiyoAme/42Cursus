/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:28:50 by hehuang           #+#    #+#             */
/*   Updated: 2025/01/24 18:24:01 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

ScalarConverter::ScalarConverter(){};
ScalarConverter::~ScalarConverter(){};

bool ScalarConverter::is_special_case(std::string val)
{
	for (int i = 0; i < 3 ; i++)
	{
		if (SPECIAL[i] == val || SPECIALF[i] == val)
		{
			std::cout	<< "char: Impossible\n"
						<< "int: Impossible\n"
						<< "float: " << SPECIALF[i] << "\n"
						<< "double: " << SPECIAL[i] << std::endl;
			return (true);
		}
	}
	return false;
}

bool ScalarConverter::is_displayable(float val)
{
	if (val >= 33 && val <= 132 )//space to '~'
	{
		std::cout	<< "char: " << static_cast<char>(val)<< "\n"
					<< "int: " << static_cast<int>(val) << "\n"
					<< "float: " << val << "\n"
					<< "double: " << static_cast<double>(val) << std::endl;
		return (true);
	}
	return (false);
}

bool ScalarConverter::is_numeric(std::string val)
{
	double max_val[2] = {2147483647.0, -2147483648.0};
	try
	{
		float res = std::stof(val);
		if (is_displayable(res))
			return (true);
		std::cout	<< "char: Non displayable\n"
					<< "int: ";
		if (res > max_val[0] || res < max_val[1])
			std::cout << "Non displayable\n";
		else
			std::cout << static_cast<int>(res) << "\n";
		std::cout	<< "float: " << val << "\n"
					<< "double: " << static_cast<double>(res) << std::endl;
		return (true);
	}
	catch (const std::exception& e)
	{
		std::cout	<< "char: Non displayable\n"
					<< "int: Non displayable\n"
					<< "float: Non displayable\n"
					<< "double: Non displayable" << std::endl;
		return (false);
    }
}

void	ScalarConverter::convert(std::string inp)
{
	if (is_special_case(inp))
		return ;
	is_numeric(inp);
}
