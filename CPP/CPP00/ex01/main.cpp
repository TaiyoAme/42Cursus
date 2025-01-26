/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:00:40 by hehuang           #+#    #+#             */
/*   Updated: 2024/11/18 22:08:53 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main (void)
{
	std::string	input;
	PhoneBook pb;
	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, input);
		if (!input.compare("ADD"))
			pb.add_contact();
		if (!input.compare("SEARCH"))
			pb.search_contact();
		if (!input.compare("EXIT") || std::cin.eof())
			break;
	}
	if (std::cin.eof())
		std::cout << std::endl;
	return 0;
}
