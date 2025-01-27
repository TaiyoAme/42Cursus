/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:55:56 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/23 19:25:14 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAPTRAP_HPP
# define SCAPTRAP_HPP

# include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap &operator=(ScavTrap const &copy);
	~ScavTrap();
	void	guardGate(void);
	void	attack(const std::string &target);

private:
	bool	guarding = false;
};

#endif // !SCAPTRAP_HPP
