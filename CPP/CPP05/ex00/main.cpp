/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:39:25 by hehuang           #+#    #+#             */
/*   Updated: 2025/03/07 18:52:17 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>
#include <string>


bool is_valid_number(const char* str) {
    if (!str || !*str)
		return false;
	
    if (!std::isdigit(str[0]) && str[0] != '+' && str[0] != '-') 
        return false;

    for (int i = 1; str[i] != '\0'; ++i) {
        if (!std::isdigit(str[i]))
			return false;
    }
    return true;
}

int main (int argc, char *argv[]) {
	
	if (argc == 2)
	{
		if (!is_valid_number(argv[1]))
			return (std::cout << "Error:\nInvalid input" << std::endl,1);
		std::string input;
		try
		{
			Bureaucrat a = Bureaucrat("Office slave", std::atoi(argv[1]));
			std::cout << "type '+' to promote and '-' to demote" << std::endl;
			Bureaucrat b = a;
			std::cout << a << "\n" <<  b << std::endl;
			while (1)
			{
				std::getline(std::cin, input);
				if (std::cin.eof())
					break;
				try
				{
					if (input[0] == '+')
						a.promote();
					else if (input[0] == '-')
						a.demote();
					std::cout << a << std::endl;
				}
				catch(const std::exception& e){std::cout << "Exception caught : " << e.what() << std::endl;}
			}
		}
		catch (const std::exception& e){std::cout << "Exception caught : " << e.what() << std::endl;}
	}
	return 0;
}
