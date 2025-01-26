/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:49:28 by hehuang           #+#    #+#             */
/*   Updated: 2024/11/14 22:35:50 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype> 

int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else if (argc > 1)
	{
		int i = 0;
		while (++i < argc)
		{
			int j = -1;
			while (argv[i][++j] != '\0')
				argv[i][j] = std::toupper(argv[i][j]);
			std::cout << argv[i];
		}
	}
	std::cout << "\n";
	return (0);
}
