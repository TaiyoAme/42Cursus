/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:39:25 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/25 18:14:31 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

int main (int argc, char *argv[]) {
	
	if (argc == 2)
	{
		std::string input;
		std::cout << "type '+' to promote and '-' to demote" << std::endl;
		Bureaucrat a = Bureaucrat("slave", std::atoi(argv[1]));
		while (1)
		{
			std::getline(std::cin, input);
			if (std::cin.eof())
				break;
			if (input[0] == '+')
				a.promote();
			else if (input[0] == '-')
				a.demote();
			std::cout << a << std::endl;
		}
	}
	return 0;
}
