/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 17:39:25 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/25 19:30:16 by hehuang          ###   ########.fr       */
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
		Form fs[4];
		try
		{
			fs[0] = Form("test1", 5, 10);
			fs[1] = Form("test2", 9, 20);
			fs[2] = Form("test3", 42, 120);
			fs[3] = Form("test4", 100, 150);
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
			a.signForm(fs[0]);
			std::cout << "---------NEXT---------" << std::endl;
			a.signForm(fs[1]);
			std::cout << "---------NEXT---------" << std::endl;
			a.signForm(fs[2]);
			std::cout << "---------NEXT---------" << std::endl;
			a.signForm(fs[3]);
			std::cout << "---------NEXT---------" << std::endl;
		}
		catch (std::exception &e) 
		{
        	std::cerr << e.what() << std::endl;
    	}
	}
	return 0;
}
