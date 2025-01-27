/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:12:17 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/16 17:28:15 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	trapA("Hugo Boss");
	ClapTrap	trapB("John Dirty");


	trapA.attack(trapB.getName());
	trapB.takeDamage(2);
	trapB.attack(trapA.getName());
	trapA.takeDamage(5);
	trapB.attack(trapA.getName());
	trapA.takeDamage(2);

	trapA.attack(trapB.getName());
	trapB.takeDamage(2);
	trapB.attack(trapA.getName());

	trapA.takeDamage(5);
	trapA.attack(trapB.getName());
	trapA.beRepaired(1);
	
	trapB.attack(trapA.getName());
	trapA.takeDamage(2);

	trapB.attack(trapA.getName());
	trapA.takeDamage(2);

	trapB.attack(trapA.getName());
	trapA.takeDamage(2);
	
	trapB.attack(trapA.getName());
	trapA.takeDamage(2);

	trapB.attack(trapA.getName());
	trapA.takeDamage(2);
	
	trapB.beRepaired(3);
	trapB.beRepaired(3);
	trapB.beRepaired(3);
	trapA.beRepaired(3);
	return (0);
}
