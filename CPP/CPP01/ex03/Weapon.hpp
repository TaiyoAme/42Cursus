/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:23:57 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/13 17:53:03 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {
public:
	Weapon();
	Weapon(std::string type);
	~Weapon();
	std::string	getType();
	void	setType(std::string newType);

private:
	std::string type;
};

#endif // !WEAPON_HPP
