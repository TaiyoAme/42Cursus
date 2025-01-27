/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:44:53 by hehuang           #+#    #+#             */
/*   Updated: 2024/12/25 16:31:13 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
#include "AMateria.hpp"

class Ice : public AMateria{
public:
	Ice();
	Ice &operator=(const Ice &copy);
	Ice(const Ice &copy);
	~Ice();
	AMateria* clone() const override;
	void use(ICharacter& target) override;


private:
	
};

#endif // !ICE_HPP
