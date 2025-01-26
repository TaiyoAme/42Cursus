/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:58:48 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/13 16:38:27 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class Zombie {
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void	annonce(void);
		void	set_name(std::string name);

	private:
		std::string name;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif // !ZOMBIE_HPP
