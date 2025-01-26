/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:58:48 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/15 16:57:49 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstring>
#include <cctype>

int main(int argc, char **argv)
{
	Harl harl;

	if (argc == 2 && strlen(argv[1]) == 1 && isdigit(argv[1][0]))
		harl.complain(argv[1][0] - '0');
	else if (argc == 2)
		harl.complain(6);
	return 0;
}
