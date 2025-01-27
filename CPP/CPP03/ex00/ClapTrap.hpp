/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:13:16 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/23 19:19:27 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# define MAX_HIT 10
# define MAX_ENERGY 10

class ClapTrap {
public:
	ClapTrap(std::string name);
	ClapTrap();
	ClapTrap &operator=(ClapTrap const &copy);
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string	getName(void);

private:
	std::string name_;
	int	hit_point_ = 10;
	int energy_point_ = 10;
	int	attack_damage_ = 0;
};

#endif
