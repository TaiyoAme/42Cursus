/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:58:48 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/13 16:57:51 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (int argc, char **argv)
{
	Zombie *horde = zombieHorde(5, "WUUUUUUUUU");
	for (int i = 0; i < 5; i ++)
		horde[i].annonce();
	delete [] horde;
	return 0;
}

