/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:28:50 by hehuang           #+#    #+#             */
/*   Updated: 2025/03/21 23:24:50 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cmath>
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

bool hasDecimal(double value)
{
    return value != std::floor(value);
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
		if (hasDecimal(res))
			std::cout	<< "float: " << res << "f" << "\n"
					<< "double: " << static_cast<double>(res) << std::endl;
		else
			std::cout	<< "float: " << res << ".0f" << "\n"
					<< "double: " << static_cast<double>(res) << ".0" << std::endl;
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

bool	ScalarConverter::check_arg(std::string argv)
{
	int i = -1;
	int point = 0;
	while (argv[++i])
	{
		if (i == 0 && (argv[i] == '+' || argv[i] == '-'))
			i++;
		if (!(argv[i] >= '0' && argv[i] <= '9' ) && argv[i]!= '.' && argv[i] != 'f')
			return (false);
		if (argv[i] == 'f' && argv[i + 1])
			return (false);
		if (argv[i] == '.')
			point ++;
	}
	if (point > 1)
		return (false);
	return (true);
}

void	ScalarConverter::convert(std::string inp)
{
	if (is_special_case(inp))
		return ;
	if (check_arg(inp))
		is_numeric(inp);
	else
	{
		std::cout	<< "char: Non displayable\n"
					<< "int: Non displayable\n"
					<< "float: Non displayable\n"
					<< "double: Non displayable" << std::endl;
	}
}
