/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:14:02 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/25 16:27:36 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
#include "AMateria.hpp"

class Cure : public AMateria{
public:
	Cure();
	Cure(const Cure &copy);
	Cure &operator=(const Cure &copy);
	~Cure();
	AMateria* clone() const override;
	void use(ICharacter& target) override;


private:
	
};
#endif
