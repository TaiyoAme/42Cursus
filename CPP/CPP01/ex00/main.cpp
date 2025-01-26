/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:58:48 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/13 16:43:08 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (int argc, char **argv)
{
	Zombie a("WOOOO");
	a.annonce();

	Zombie *b = newZombie("WAAAA");
	b->annonce();

	randomChump("WUUUUU");
	delete b;
	return 0;
}

