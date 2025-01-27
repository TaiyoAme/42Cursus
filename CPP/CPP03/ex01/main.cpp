/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:12:17 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/16 19:09:23 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	b("Morgan");
	ClapTrap	c("Hugues");
	b.takeDamage(3);
	b.takeDamage(95);
	b.beRepaired(3);
	b.takeDamage(95);
	b.attack("Eric");
	b.attack("Eric");
	b.attack("Eric");
	b.beRepaired(6);
	b.attack("Eric");
}
