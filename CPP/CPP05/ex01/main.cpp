/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:39:25 by hehuang           #+#    #+#             */
/*   Updated: 2025/03/07 19:20:25 by hehuang          ###   ########.fr       */
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
	
	if (argc == 4)
	{
		if (!is_valid_number(argv[2]) || !is_valid_number(argv[1]) || !is_valid_number(argv[3]))
			return (std::cout << "Error:\nInvalid input (number between 1 and 150)" << std::endl,1);
		try
		{
			Form f = Form("formula 1", std::atoi(argv[2]), std::atoi(argv[3]));
			std::cout << f << std::endl;
		try
		{
			Bureaucrat a = Bureaucrat("Office slave", std::atoi(argv[1]));
			std::cout << a << std::endl;
			a.signForm(f);
			std::cout << f << std::endl;
		}
		catch (const std::exception& e){std::cout << "Exception caught : " << e.what() << std::endl;}
			
		}
		catch (std::exception &e) 
		{
        		std::cerr << e.what() << std::endl;
    		}
	}
	return 0;
}
