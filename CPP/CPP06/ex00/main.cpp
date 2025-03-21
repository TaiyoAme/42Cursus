/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:43:35 by hehuang           #+#    #+#             */
/*   Updated: 2025/01/24 17:54:02 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main (int argc, char *argv[])
{
	if (argc == 2)
	{
		ScalarConverter *a;
		a->convert(argv[1]);
	}
	return 0;
}
