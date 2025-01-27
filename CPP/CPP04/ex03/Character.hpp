/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:59:23 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/25 16:23:04 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include <string>

class Character : public ICharacter{
public:
	Character();
	Character(std::string name);
	Character(const Character &src);
	Character &operator=(const Character &copy);
	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

private:
	std::string name_;
	AMateria *inventory_[4];
	AMateria *floor_[10];
};
